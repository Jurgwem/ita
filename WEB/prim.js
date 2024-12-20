const primText = document.getElementById("primText");
const numText = document.getElementById("zahl");

var number = 0;
numText.innerHTML = number;

function addNum()
{
    number++;
    numText.innerHTML = number;
}

function check()
{
    let tmp = true;

    for (let x = 2; x < number; x++) {
        if (number % x == 0) {
            tmp = false;
        }
    }

    if(number == 2) {
        tmp = true;
    }

    if (tmp) {
        primText.innerHTML = "Ist eine Primzahl";
    } else {
        primText.innerHTML = "Ist keine Primzahl";
    }

    number = 0;
    numText.innerHTML = number;
}