const kakashi_paper = document.getElementById("kakashi_paper");
const kakashi_rock = document.getElementById("kakashi_rock");
const kakashi_scissor = document.getElementById("kakashi_scissor");

const kakashi_score = document.getElementById("kscore");

const guy_score = document.getElementById("gscore");
const guy_paper = document.getElementById("guy_paper");
const guy_stone = document.getElementById("guy_stone");
const guy_scissor = document.getElementById("guy_scissor");

let loader = document.getElementById('pre-loader')
let user_score = 0;
let computer_score = 0;

function getComputerChoice() {
  const max = 3;
  const min = 1;
  let computerChoice = Math.floor(Math.random() * (max - min + 1) + min);
  //console.log(computerChoice)
  return computerChoice;
}

function playRound(playerSelection, computerSelection) {
  guy_paper.classList.add("toHide");
  guy_scissor.classList.add("toHide");
  guy_stone.classList.add("toHide");
  guy_paper.classList.remove("toShow");
  guy_scissor.classList.remove("toShow");
  guy_stone.classList.remove("toShow");

  switch (computerSelection) {
    case 1:
      computerSelection = "rock";
      guy_stone.classList.add("toShow");
      break;

    case 2:
      computerSelection = "paper";
      guy_paper.classList.add("toShow");
      break;

    case 3:
      computerSelection = "scissor";
      guy_scissor.classList.add("toShow");
      break;
  }

  switch (playerSelection) {
    case "rock":
      if (computerSelection == "rock") {
        msg.textContent = "Tie";
        return "Tie";
      } else if (computerSelection == "paper") {
        computer_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Lost";
        return "You Lost";
      } else if (computerSelection == "scissor") {
        user_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Won";
        return "You Won";
      }
      break;
    case "scissor":
      if (computerSelection == "rock") {
        computer_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Lost";
        return "You Lost";
      } else if (computerSelection == "paper") {
        user_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Won";
        return "You Won";
      } else if (computerSelection == "scissor") {
        msg.textContent = "Tie";
        return "Tie";
      }
      break;
    case "paper":
      if (computerSelection == "rock") {
        user_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Won";
        return "You Won";
      } else if (computerSelection == "paper") {
        msg.textContent = "Tie";
        return "Tie";
      } else if (computerSelection == "scissor") {
        computer_score += 1;
        kscore.textContent = user_score;
        gscore.textContent = computer_score;
        msg.textContent = "You Lost";
        return "You Lost";
      }
      break;
  }
}

function checkResult() {
  if (user_score == 3) {
    vid.classList.add("toHide")

    //document.getElementById("score_section").style.display = "none";
    
    document.getElementById('kakashiwon').classList.remove('toHide')
    return user_score;
  } else if (computer_score == 3) {
    vid.classList.add("toHide")


    //document.getElementById("score_section").style.display = "none";
    document.getElementById('guywon').classList.remove('toHide')
    return computer_score;
  } else {
    return 0;
  }
}

function displayResult(result) {
  if (result == user_score) {
    console.log("kakashi won");
    terminate();
  } else console.log("guy won");
  terminate();
}
function terminate() {
  kakashi_paper.classList.add("toHide");
  kakashi_rock.classList.add("toHide");
  kakashi_scissor.classList.add("toHide");
  guy_paper.classList.remove("toShow");
  guy_stone.classList.remove("toShow");
  guy_scissor.classList.remove("toShow");
  guy_paper.classList.add("toHide");
  guy_stone.classList.add("toHide");
  guy_scissor.classList.add("toHide");
}
let playerChoice = "";

kakashi_paper.addEventListener("click", () => {

  playerChoice = "paper";
  console.log("clicked1");
  setTimeout(() => {
    next();
  }, 1800);
});

kakashi_rock.addEventListener("click", () => {

  
  setTimeout(() => {
    next();
  }, 1800);
  playerChoice = "rock";
});

kakashi_scissor.addEventListener("click", () => {
  kakashi_paper.classList.remove("toGlow");
  kakashi_rock.classList.remove("toGlow");
  kakashi_scissor.classList.add("toGlow");
  
  setTimeout(() => {
    next();
  }, 1800);

  console.log("clicked3");
  playerChoice = "scissor";
});
var vid = document.getElementById("video");

function playVid() {
  vid.play();
}

// User's Button Event Listener to Play the Game
function next() {
  let computerChoice = getComputerChoice();
  let result = playRound(playerChoice, computerChoice);
  if (checkResult() != 0) {
    displayResult(result);
  }
  console.log(result, user_score, computer_score);
}
/*   selectionPlayer.appendChild(createParagWithText(playerSelection));
  selectionComputer.appendChild(createParagWithText(computerSelection)); */

  window.addEventListener('load', () => {
    setTimeout(() => {
      loader.style.transition = "1sec ease";
      loader.style.display = "none";
    }, 1500);
  })