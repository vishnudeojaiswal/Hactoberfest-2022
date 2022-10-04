

let rows, mines;
let mineSpots = [];
let cellsUncovered = 0, flagged = 0, isGameOver = false, isWon = false;


function init() {
	cellsUncovered = 0;
	flagged = 0;
	isGameOver = false;
	isWon = false;
	let rowCount = window.prompt('Enter the number of rows');
	let mineCount = window.prompt('Enter the number of mines');
	setRows(rowCount);
	setMineCount(mineCount);
}



function handleClick(e) {
	if(isGameOver) return;
	if(e.target.classList.contains('uncovered')) return;
	if(e.button === 0)
		leftClick(e.target);
	else if(e.button === 2){
		e.preventDefault();
		rightClick(e.target);
	}
}

function leftClick(cell) {
	if(cell.innerHTML === '🚩')
		return;
	++cellsUncovered;
	cell.classList.remove('covered');
	if(cell.dataset.value === "-1"){
		// console.log('mine');
		cell.classList.add('uncovered');
		cell.innerHTML = '💣';
		reveal();
		setTimeout(()=>{window.alert('You clicked on a mine. You lost!');}, 1500)
	}
	else{
		if(cell.dataset.value === "0") {
			const i = +cell.dataset.index;
			cell.classList.add('uncovered');
			const directions = directionsToCheck(i);
			const regions = [];
			if(directions[0]) { //if above needs to be checked
				regions.push(i-rows);
				if(directions[2]) { //if right
					regions.push(i-rows+1);
				}
				if(directions[3]) { //if left
					regions.push(i-rows-1);
				}
			}
			if(directions[1]) { //if below
				regions.push(i+rows);
				if(directions[2]) { //if right
					regions.push(i+rows+1);
				}
				if(directions[3]) { //if left
					regions.push(i+rows-1);
				}
			}
			if(directions[2]) { //if right
				regions.push(i+1);
			}
			if(directions[3]) { //if left
				regions.push(i-1);
			}
			regions.forEach( region => {
				const cellToUncover = document.querySelector(`.covered[data-index="${region}"]`);
				if(cellToUncover != null)
					leftClick(cellToUncover);	
			});

		}
		else {
			cell.classList.add('uncovered');
			cell.innerHTML = cell.dataset.value;
		}
	}
	won();
}

function rightClick(cell) {
	if(cell.innerHTML === '' && flagged<mines) {
		cell.innerHTML = '🚩';
		++flagged;
	}
	else {
		cell.innerHTML = '';
		--flagged;
	}
	document.querySelector('#count').innerHTML = mines - flagged;
	won();
}

function setRows(rowCount) {
	if(rowCount < 2) {
		window.alert('There should be at least 2 rows/columns');
		init();
	} 
	else {
		rows = +rowCount;
		let size = 50;
		let render = '';
		let wrapperSize = size*rows;
		let fontSize = Math.sqrt(5)/Math.sqrt(rows) *40;
		console.log(fontSize);
		document.documentElement.style.setProperty('--tiles', rows);
		document.documentElement.style.setProperty('--size', size +'px' );		
		document.documentElement.style.setProperty('--wrapperSize', wrapperSize +'px' );		
		document.documentElement.style.setProperty('--fontSize', fontSize +'px' );		
		for(let i=0; i < rows; i++) {
			for(let j=0; j<rows; j++) {
				render = render + `<div class="cell covered" data-index=${(i*rows)+(j+1)} ></div>`;
			}
		}
		document.querySelector('.board').innerHTML = render;		
	}

	const cells = document.querySelectorAll('.cell');
	cells.forEach(cell => cell.addEventListener('mousedown', (e) => handleClick(e) ));
}


function setMineCount(mineCount) {
	if(mineCount >= rows*rows -1 ) {
		window.alert('Too many mines');
		init();
	}
	else if(mineCount <= 0 ) {
		window.alert('There should be at least one mine');
		init();
	}
	else {
		mines = +mineCount;
		plantMines();
	}
	document.querySelector('#count').innerHTML = mines - flagged;
}

function plantMines() {
	let landMines = [];
	while(landMines.length < mines) {
		let num = Math.floor(Math.random() * rows * rows);
		if( landMines.indexOf(num) === -1) {
			landMines.push(num);
			document.querySelector(`.cell[data-index="${num+1}"]`).classList.add('mine');
		}
	}
	mineSpots = landMines;
	updateCellValues();
}

function directionsToCheck(cellNumber) {
	const i = cellNumber - 1;
	let result = [1,1,1,1];
	if(i<rows)
		result[0] = 0;
	if(i%rows === 0)
		result[3] = 0;
	if((i+1)%rows === 0)
		result[2] = 0;
	if(i+rows > rows*rows)
		result[1] = 0;
	return result;
}

function updateCellValues() {
	// console.log(mineSpots);
	const cells = document.querySelectorAll('.cell');
	
	cells.forEach( cell => {
		const i = cell.dataset.index - 1;
		if(mineSpots.indexOf(i)!== -1) {
			cell.setAttribute('data-value', -1);
			return;
		}
		let mineCount = 0;
		const directions = directionsToCheck(i+1);
		if(directions[0]) { //if above needs to be checked
			if(mineSpots.indexOf(i-rows)!== -1) // check north
				++mineCount;
			if(directions[2]) { //if right
				if(mineSpots.indexOf(i-rows+1)!== -1) // check NE
					++mineCount;
			}
			if(directions[3]) { //if left
				if(mineSpots.indexOf(i-rows-1)!== -1) //check NW
					++mineCount;
			}
		}
		if(directions[1]) { //if below
			if(mineSpots.indexOf(i+rows)!== -1) //check south
				++mineCount;
			if(directions[2]) { //if right
				if(mineSpots.indexOf(i+rows+1)!== -1) //check SE
					++mineCount;
			}
			if(directions[3]) { //if left
				if(mineSpots.indexOf(i+rows-1)!== -1) //check SW
					++mineCount;
			}
		}
		if(directions[2]) { //if right
			if(mineSpots.indexOf(i+1)!== -1) //check E
				++mineCount;
		}
		if(directions[3]) { //if left
			if(mineSpots.indexOf(i-1)!== -1) //check W
				++mineCount;
		}
		cell.setAttribute('data-value', mineCount);
	})
	// console.log(directionsToCheck(1));
}

function won() {
	if(cellsUncovered+flagged === (rows*rows)) {
		window.alert('You Won');
		isWon = true;
		reveal();
	}

}

function reveal() {
	const cellsToReveal = document.querySelectorAll('.mine');
	cellsToReveal.forEach( cell => {
		cell.classList.remove('covered');
		cell.classList.add('uncovered');
		if(cell.dataset.value === "-1"){
			cell.innerHTML = "💣";
			if(!isWon)
				setTimeout(() => {cell.innerHTML = '💥'}, 1000)
		}
		else
			cell.innerHTML = cell.dataset.value;
	} );
	isGameOver = true;
}