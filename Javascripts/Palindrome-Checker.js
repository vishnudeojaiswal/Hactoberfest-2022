
function palindrome(str) {
 // step 1: uppercase a string and remove all non-alphanumerical character
    let upperCaseString = str.toUpperCase();

    let nonAlphaNumericalString = upperCaseString.replace(/[\W_]/g, '');
    
//step 2: use chaining methods with  built-in methods to reverse string
    
    let reversedString = nonAlphaNumericalString.split("").reverse().join("");

//step 3: Compare  the non-alphanumerical string to the reversed string
    
  return reversedString === nonAlphaNumericalString
}


// palindrome("eye"); 
// should return true.

// palindrome("_eye"); 
// should return true.

// palindrome("race car"); 
// should return true.

// palindrome("not a palindrome"); 
// should return false.

// palindrome("A man, a plan, a canal. Panama"); 
// should return true.

// palindrome("never odd or even"); 
// should return true.

// palindrome("nope"); 
// should return false.

// palindrome("almostomla"); 
// should return false.

// palindrome("My age is 0, 0 si ega ym."); 
// should return true.

// palindrome("1 eye for of 1 eye."); 
// should return false.

// palindrome("0_0 (: /-\ :) 0-0"); 
// should return true.

// palindrome("five|\_/|four"); 
// should return false.