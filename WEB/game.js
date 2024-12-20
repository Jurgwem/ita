//t-0GyIHg2VsG
window.requestAnimFrame = (function(){  //framerate shit
	return window.requestAnimationFrame ||
	window.webkitRequestAnimationFrame ||
	window.mozRequestAnimationFrame ||
	function( callback ) {
		window.setTimeout(callback, 1000 / 60);
	};
})();

var canvas = document.getElementById('mainCanvas');
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight * 0.85;
var ctx = canvas.getContext("2d");
    ctx.imageSmoothingEnabled = false;  //antialiaslising doesnt to shit, rip, fix blurry edges later 
var scoreText = document.getElementById('score');
var lcText = document.getElementById('lc');
var modText = document.getElementById('spMod');
var tutorial = document.getElementById('tutorial');

//game vars
var gameHeight = 23;                //well its 24 but whatever but its actually 20 but whatever
var gameWidth = 9;                  //well its 10 but whatever, also use this instead of 'game[x].length'
var tileSize = canvas.height / 26;  //scale of each tile
var pScore = 0;                     //player score
var pClear = 0;                     //num. of lines cleared this game
var speedMod = 1;                   //display value, not relevant for gameplay
var diff = 10;                      //difficulty, aka by what should the tickrate be shortened by?
var debug = true;                  //print out other stuff to the console
var debug2 = true;                 //board print out, trashes up the console
var input = 'NA';
//this is certified dumb but it'll work for now
//possible stuff: 'NA', 'left', 'right', 'up', 'down', 'c', 'x',
var tickrate = 500;                 //gamespeed, todo: is this framerate / Hz dependant? if so then im fucked
var tick = 0;                       //debug shit
var moveCheck = false;              //check if piece can move sideways
var canDrop = false;                //check if current piece can drop a layer down
var moveMode = false;               //true = movement mode, false = rotation mode
var randomPiece = 0;                //random number between 0 and 6 to decide which piece will be next
var middle = 5;                     //center column for piece spawnpoint, current: middle right
var center = 3;                     //center for new rotation because ass
var rotInput = 0;                   //input for rotation mode;
var translatedRotation = 0;         //translated rotation index (from randomPiece -> value in rotate(switch))
var rotationIndex = 0;              //final roation index (random + user input) to be fed into rotate(switch)
var canClear = false;               //check if line should be cleared
var canMove = false;                //check if line should be moved entirely
var stateCounter = 0;               //prevent infinite spin mode
var dead = false;                   //is player dead? 
var rotationTime = 12;              //amount of ticks the player gets to rotate the piece max

//colors (has to be in hex)
var emptyCol = '#b3b3b3';           //empty cells
var conCol = '#88d26a';             //player controlled cells
var placedCol = '#000000';          //solid cells
var rotStateCol = '#696969';        //top rotate state cells
var playerRotStateCol = '#c9cc00';  //player controlled tiles whilst in rotation state
var prevCol = '#888888';            //hard drop preview tiles' color

//TODO:
//hard drop preview?
//
//hi-score system
//fix the magnum-opus switch case at the bottom cause holy shit its disgusting (i wont fix this shit, it works so its perfectly fine)

const game = [ //gameboard array
    ["3", "3", "3", "3", "3", "3", "3", "3", "3", "3", ], //rotateState, 4 rows bc good code //0th
    ["3", "3", "3", "3", "3", "3", "3", "3", "3", "3", ],
    ["3", "3", "3", "3", "3", "3", "3", "3", "3", "3", ],
    ["3", "3", "3", "3", "3", "3", "3", "3", "3", "3", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ], //4th, game actually begins
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ],
    ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ] //23th, end
]
//first update so the website doesnt seem "frozen"
updateBoard(game);
updateScores();
gameplay();
//mental gymnastics:
//0 = blanks
//1 = player controlled
//2 = stationairy
//3 = cosmetic rotateState rows because good game indication
//4 = player controlled piece while in rotation state
//5 = drop-down preview indicator

//MAIN GAME LOOP YIPPEEEE
function gameplay() {
    if (hasPlayer(game)) {
        moveMode = true;
    } else {
        moveMode = false;
        if (!hasRotPlayer(game)) {
            stateCounter = 0;
            randomPiece = Math.floor(Math.random() * 6); //generate random number between 0 and 6, so 7 possibilites
            switch(randomPiece){    //translate random number to rotate index
                case 0:
                    translatedRotation = 0;
                    break;

                case 1:
                    translatedRotation = 4;
                    break;
                
                case 2:
                    translatedRotation = 8;
                    break;

                case 3:
                    translatedRotation = 12;
                    break;

                case 4:
                    translatedRotation = 16;
                    break;

                case 5:
                    translatedRotation = 20;
                    break;

                case 6:
                    translatedRotation = 24;
                    break;
            }
            //rotate(game, translatedRotation);
            rotInput = 0;
            //newRotate(game, randomPiece, rotInput);
            rotate(game, translatedRotation);
            if(debug2){
                console.log("randomPiece: " + randomPiece);
                console.log("translatedRotation: " + translatedRotation);
                console.log("rotInput = " + rotInput);
            }
        }
    }
    if(moveMode){  //movement mode code
        dropDown(game);
        topShelf(game);
        updateBoard(game);
        updateScores();

    } else {    //rotation mode code
        updateBoard(game);
        stateCounter++;
    }
    if (stateCounter >= rotationTime) {
        transferState(game);
    }

    if(debug2){
        console.log("input: " + input);
        console.log("moveMode = " + moveMode);
        console.log("stateCounter = " + stateCounter);
        console.log("tickRate = " + tickrate);
    }
    input = 'NA';
    setTimeout(() => {
        if(!dead) {
            gameplay();
        } else {
            gameover();
        }
    }, tickrate);
}

function dropDown(board) //basic dropping down a layer
{
    canDrop = true;
    for (var x = gameWidth; x >= 0; x--) { //DROP PHYSICS, check if below is either edge of world or another solid piece
        for (var y = gameHeight; y >= 0; y--) {
            if (board[y][x] == '1') {
                if(y == 23) {
                    canDrop = false;
                    break;
                }
                if(board[y + 1][x] == '2') {
                    canDrop = false;
                    break;
                }
            }
        }
    }
    if(canDrop) {   //if there is nothing important below, go down a layer
        for (var x = gameWidth; x >= 0; x--) {
            for (var y = gameHeight; y >= 0; y--) {
                if (board[y][x] == '1') {
                    board[y][x] = '0';
                    board[y + 1][x] = '1';
                }
            }
        }
    } else {        //otherwise solidify
        solidify(game);
    }
    for (var d = 0; d <= 3; d++) {
        lineClear(game);
    }
}

function updateBoard(board) //visual update of the game board, only the board, not the scores
{
    ctx.clearRect(0, 0, canvas.width, canvas.height);   //clear
    //preview(game);

    if (debug2){ //print out tick count + game as array to console
        console.log("----------START----------");
        for (var y = 0; y <= gameHeight; y++) {  
            console.log(board[y]);
        }
        console.log("----------END----------");
        console.log("updating board, tick no. " + tick)
    }

    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            ctx.beginPath();
            switch(board[y][x]) {
                case '0':
                    ctx.fillStyle = emptyCol;
                    break;
                
                case '1':
                    ctx.fillStyle = conCol;
                    break;

                case '2':
                    ctx.fillStyle = placedCol;
                    break;

                case '3':
                    ctx.fillStyle = rotStateCol;
                    break;

                case '4':
                    ctx.fillStyle = playerRotStateCol;
                    break;

                case '5':
                    ctx.fillStyle = prevCol;
                    break;

                default:
                    ctx.fillStyle = 'red';
                    break;
            }
            //dumb anti alialising? the "[...] tilesize - 0" part shows alialised edges when in fullscreen, replace 0 with 1 to fix, which makes the board uneven by 1 pixel per row, wtf
            ctx.fillRect((canvas.width / 2) - ((gameWidth * tileSize) / 2) + (tileSize * x), (canvas.height / 2) - ((gameHeight * tileSize) / 2) + ((tileSize - 0) * y), tileSize, tileSize);
            ctx.closePath()
            ctx.stroke();
        }
    }
    tick++;
}

function hasPlayer(board)   //check if given board has player inside of it, return true / false
{
    var hasPlayer = false;
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            if (board[y][x] == '1') {
                hasPlayer = true;
            }
        }
    }
    return hasPlayer;
}

function hasRotPlayer(board)   //check if given board has rotation player inside of it, return true / false
{
    var hasPlayer = false;
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            if (board[y][x] == '4') {
                hasPlayer = true;
            }
        }
    }
    return hasPlayer;
}

function topShelf(board)    //re-render the top row of grey tiles
{
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = 3; y >= 0; y--) {
            if (board[y][x] == '2') {
                dead = true;
            }
            if (board[y][x] == '0') {
                board[y][x] = '3';
            }
        }
    }
}

function transferState(board)   //swap out player-rotation-tiles with player-dropping-down-tiles
{
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = 3; y >= 0; y--) {
            if (board[y][x] == '4') {
                board[y][x] = '1';
            }
        }
    }
}

function lineClear(board)   //janky line clear part1, detect full lines 
{
    for (var y = gameHeight; y >= 0; y--) {
        canClear = true;
        for (var x = gameWidth; x >= 0; x--) {
            if (board[y][x] != '2') {
                canClear = false;
            }
        }
        if (canClear) { //PUT CODE HERE FOR MOVING LINE DOWN (i did yay)
            for (var l = gameWidth; l >= 0; l--) {
                board[y][l] = '0';
            }
            tickrate = tickrate - diff;   //SPEEDUP FACTOR
            speedMod = speedMod + (diff / tickrate);    //dumbass
            pScore = pScore + 2500;
            pClear++;
            boardDown(board);
        }
    }
}

function boardDown(board)   //janky line clear part2
{
    if (debug) {
        console.log("boardDown");
    }
    
    for (var y = 0; y <= gameHeight; y++) {
        canClear = true;
        for (var x = 0; x <= gameWidth; x++) {
            if (board[y][x] == '2') {
                canClear = false;
                if (debug) {
                    console.log("canClear = false");
                }
            }
        }
        if (canClear) {
            if (debug) {
                console.log("canClear = true");
            }
            for (var yy = y; yy >= 3; yy--) {
                for (x = 0; x <= gameWidth; x++) {
                    if (board[yy][x] == '0' && board[yy - 1][x] == '2') {
                        board[yy][x] = '2';
                        board[yy - 1][x] = '0'; 
                    }
                }
            }
        }
    }
    updateScores();
}

function solidify(board) {  //swap out player controlled tiles with soid tiles
    var tmp = 0;
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            if (board[y][x] == '1') {
                board[y][x] = '2';
                tmp++;
            }
        }
    }
    if (debug) {
        console.log("solidified " + tmp + " tiles");
    }
}

function preview(backup)    //WIP preview system
{
    let test = true;

    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            if (game[y][x] == '1' || game[y][x] == '4') {
                backup[y][x] = '5';
            }
        }
        backup[y][x] = game[y][x];
    }

    for (var failsafe = 0; failsafe <= gameHeight; failsafe++) {
        test = true;
        for (var x = gameWidth; x >= 0; x--) {
            for (var y = gameHeight; y >= 0; y--) {
                if (backup[y][x] == '5') {
                    if (game[y + 1][x] == '2') {
                        test = false;
                    }
                }
                if (y == gameHeight) {
                    test = false;
                }
            }
        }
        if (test) {
            for (var x = gameWidth; x >= 0; x--) {
                for (var y = gameHeight; y >= 0; y--) {
                    if (backup[y][x] == '5') {
                        backup[y][x] = '0';
                        backup[y][x] = '5';
                    }
                }
            }
        }
    }
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = gameHeight; y >= 0; y--) {
            if (backup[y][x] = '5') {
                backup[y][x] = '0';
                game[y][x] = '5';
            }
        }
    }
}

function updateScores() {   //update the scores on the side (why did i do it like this, move this in the main update-function)
    if (debug2) {
        console.log("updating scores");
    }
    scoreText.innerHTML = "Points: " + pScore;
    lcText.innerHTML = "Lines Cleared: " + pClear;
    modText.innerHTML = "Speed Mod: " + speedMod.toFixed(2) + "x";
}

function gameover()     //delete the game board and center the player scores
{
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    scoreText.style.marginLeft = "40%";
    lcText.style.marginLeft = "40%";
    modText.style.marginLeft = "40%";
    tutorial.style.opacity = 0;
}

//input mapping
window.addEventListener("keydown", function (event) {
    if (event.defaultPrevented) {
      return;
    }
    switch (event.key) {
        case "ArrowDown":   //SINGLE LAYER DOWN
            input = 'down';
            if(!dead) {
                if (!moveMode) {
                    transferState(game);
                } else {
                if(hasPlayer(game) || hasRotPlayer(game)) {
                    pScore++;
                    updateScores();
                }
                
                dropDown(game);
                topShelf(game);
                updateBoard(game);
                }
            }
            break;

        case "ArrowUp":     //HARD DROP, AS FAR DOWN AS POSSIBLE
            input = 'up';
            if(!dead) {
                if (!moveMode) {
                    transferState(game);
                }
                if(hasPlayer(game) || hasRotPlayer(game)) {
                    pScore = pScore + 100;
                    updateScores();
                }
                while(hasPlayer(game)){
                    dropDown(game);
                    topShelf(game);
                    updateBoard(game);
                }
            }
            break;

        case "ArrowLeft":   //MOVEMENT LEFT
            input = 'left';
            if(!dead) {
                if (!moveMode) {
                    transferState(game);
                }
                moveCheck = true;
                for (var y = 0; y <= gameHeight; y++) { //check for collision at the bottom
                    if (game[y][0] == '1') {
                        moveCheck = false;
                        break;
                    }
                }
                for (var y = 0; y <= gameHeight; y++) { //check for collision on the left
                    for (var x = 0; x <= gameWidth; x++) {
                        if (game[y][x] == '1' && game[y][x - 1] == '2') {
                            moveCheck = false;
                        }
                    }
                }
                if (moveCheck) {
                    for (var x = 0; x <= gameWidth; x++) {
                        for (var y = gameHeight; y >= 0; y--) {
                            if (game[y][x] == '1') {
                                game[y][x - 1] = '1';
                                game[y][x] = '0';
                            }
                        }
                    }
                    moveCheck = false;
                }
                topShelf(game);
                updateBoard(game);
            }
            break;

        case "ArrowRight":  //MOVEMENT RIGHT
            input = 'right';
            if(!dead) {
                if (!moveMode) {
                    transferState(game);
                }
                moveCheck = true;
                for (var y = 0; y <= gameHeight; y++) { //check for collision on the bottom
                    if (game[y][gameWidth] == '1') {
                        moveCheck = false;
                        break;
                    }
                }
                for (var y = 0; y <= gameHeight; y++) { //check for collision on the right
                    for (var x = 0; x <= gameWidth; x++) {
                        if (game[y][x] == '1' && game[y][x + 1] == '2') {
                            moveCheck = false;
                        }
                    }
                }
                if (moveCheck) {
                    for (var x = gameWidth; x >= 0; x--) {
                        for (var y = gameHeight; y >= 0; y--) {
                            if (game[y][x] == '1') {
                                game[y][x + 1] = '1';
                                game[y][x] = '0';
                            }
                        }
                    }
                    moveCheck = false;
                }
                topShelf(game);
                updateBoard(game);
            }
            break;

        case "c":   //rotate ->
            input = 'c';
            if(!dead) {
                if (!moveMode){
                    if (rotInput >= 3) {
                        rotInput = 0;
                    } else {
                        rotInput++;
                    }
                    rotationIndex = translatedRotation + rotInput;
                    rotate(game, rotationIndex);
                    updateBoard(game);
                }
            }
            break;

        case "C":   //rotate ->, but with capslock
            input = 'c';
            if(!dead) {
                if (!moveMode){
                    if (rotInput >= 3) {
                        rotInput = 0;
                    } else {
                        rotInput++;
                    }
                    rotationIndex = translatedRotation + rotInput;
                    rotate(game, rotationIndex);
                    updateBoard(game);
                }
            }
            break;

        case "x":   //rotate <-
            input = 'x';
            if(!dead) {
                if (!moveMode){
                    if (rotInput <= 0) {
                        rotInput = 3;
                    } else {
                        rotInput--;
                    }
                    rotationIndex = translatedRotation + rotInput;
                    rotate(game, rotationIndex);
                    //newRotate(game, randomPiece, rotInput);
                    updateBoard(game);
                }
            }
            break;

        case "X":   //roatet <-, but with capslock
            input = 'x';
            if(!dead) {
                if (!moveMode){
                    if (rotInput <= 0) {
                        rotInput = 3;
                    } else {
                        rotInput--;
                    }
                    rotationIndex = translatedRotation + rotInput;
                    rotate(game, rotationIndex);
                    updateBoard(game);
                }
            }
            break;
    
        default:
            return; 
    }
    event.preventDefault();
    }, true
);


//HELL DO NOT TOUCH, DISGUSTANG
function rotate(board, input)
{
    for (var x = gameWidth; x >= 0; x--) {
        for (var y = 3; y >= 0; y--) {
                board[y][x] = '3';
        }
    }
    if (debug) {
        console.log("input: " + input);
        console.log("moveMode: " + moveMode);
    }
    switch(input){
        case 0:   //I-Piece
            board[0][middle] = '4';
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[3][middle] = '4';
            break;
        
        case 1:
            board[2][middle - 2] = '4';
            board[2][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle + 1] = '4';
            break;

        case 2:
            board[0][middle - 1] = '4';
            board[1][middle - 1] = '4';
            board[2][middle - 1] = '4';
            board[3][middle - 1] = '4';
            break;

        case 3:
            board[1][middle - 2] = '4';
            board[1][middle - 1] = '4';
            board[1][middle] = '4';
            board[1][middle + 1] = '4';
            break;
        
        case 4:   //J-Piece
            board[1][middle - 1] = '4';
            board[2][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle + 1] = '4';
            break;
        
        case 5:
            board[1][middle] = '4';
            board[1][middle - 1] = '4';
            board[2][middle - 1] = '4';
            board[3][middle - 1] = '4';
            break;

        case 6:
            board[1][middle - 2] = '4';
            board[1][middle - 1] = '4';
            board[1][middle] = '4';
            board[2][middle] = '4';
            break;

        case 7:
            board[0][middle] = '4';
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[2][middle - 1] = '4';
            break;

        case 8:   //L-Piece
            board[0][middle - 1] = '4';
            board[1][middle - 1] = '4';
            board[2][middle - 1] = '4';
            board[2][middle] = '4';
            break;
        
        case 9:
            board[1][middle] = '4';
            board[1][middle - 1] = '4';
            board[1][middle + 1] = '4';
            board[2][middle - 1] = '4';
            break;

        case 10:
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[3][middle] = '4';
            board[1][middle - 1] = '4';
            break;

        case 11:
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[2][middle - 1] = '4';
            board[2][middle - 2] = '4';
            break;

        case 12:   //O-Piece
        case 13:
        case 14:
        case 15:
            board[1][middle] = '4';
            board[1][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle - 1] = '4';
            break;
        
        case 16:  //S-Block
        case 18:
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[1][middle + 1] = '4';
            board[2][middle - 1] = '4';
            break;

        case 17:
        case 19:
            board[0][middle - 1] = '4';
            board[1][middle - 1] = '4';
            board[1][middle] = '4';
            board[2][middle] = '4';
            break;

        case 20:  //T-Piece
            board[1][middle] = '4';
            board[2][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle + 1] = '4';
            break;

        case 21:
            board[1][middle] = '4';
            board[2][middle + 1] = '4';
            board[2][middle] = '4';
            board[3][middle] = '4';
            break;

        case 22:
            board[2][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle + 1] = '4';
            board[3][middle] = '4';
            break;

        case 23: 
            board[1][middle] = '4';
            board[2][middle] = '4';
            board[2][middle - 1] = '4';
            board[3][middle] = '4';
            break;

        case 24:  //Z-Piece
        case 26:
            board[1][middle] = '4';
            board[1][middle - 1] = '4';
            board[2][middle] = '4';
            board[2][middle + 1] = '4';
            break;

        case 25:
        case 27:
            board[0][middle + 1] = '4';
            board[1][middle + 1] = '4';
            board[1][middle] = '4';
            board[2][middle] = '4';
            break;

        default:
            board[0][0] = 99;
    }
}