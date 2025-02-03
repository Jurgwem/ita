//document.addEventListener("DOMContentLoaded", (event) => {
    function formClick()
    {
        var parent = document.getElementById("awesomesauce")
        


        var name = document.getElementById("nameForm").value
        var child = document.createElement("div")
        child.innerText = "name: " + name;
        parent.appendChild(child)

        var firstname = document.getElementById("firstnameForm").value
        var child = document.createElement("div")
        child.innerText = "firstName: " + firstname;
        parent.appendChild(child)

        var gender = document.getElementsByClassName("genderForm")
        var child = document.createElement("div")
        child.innerText = "genderM: " + gender[0].checked;
        parent.appendChild(child)
        var child = document.createElement("div")
        child.innerText = "genderF: " + gender[1].checked;
        parent.appendChild(child)
        var child = document.createElement("div")
        child.innerText = "genderD: " + gender[2].checked;
        parent.appendChild(child)

        var birthday = document.getElementById("birthdayForm").value
        var child = document.createElement("div")
        child.innerText = "birthday: " + birthday;
        parent.appendChild(child)

        var mail = document.getElementById("mailForm").value
        var child = document.createElement("div")
        child.innerText = "mail: " + mail;
        parent.appendChild(child)

        var interests = document.getElementById("interestsForm").value
        var child = document.createElement("div")
        child.innerText = "interests: " + interests;
        parent.appendChild(child)

        var anliegen = document.getElementById("anliegenForm").value
        var child = document.createElement("div")
        child.innerText = "anliegen: " + anliegen;
        parent.appendChild(child)

        var body = document.querySelector("body")
        body.style.backgroundColor = "#FFFF00";
        

        //console.log(name)
        //console.log(firstname)
        //for(var x = 0; x <= 2; x++) {
        //    console.log(gender[x].checked)
        //}
        //console.log(birthday)
        //console.log(mail)
        //console.log(interests)
        //console.log(anliegen)
    }

let tasks = [];

const taskInput = document.getElementById('task-input');
const addTaskButton = document.getElementById('add-task');
const taskList = document.getElementById('task-list');


function addTask(task) {
    tasks.push(task);
    renderTasks();
}

function deleteTask(index) {
    tasks.splice(index, 1);
    renderTasks();
}

function editTask(index, newTask) {
    tasks[index] = newTask;
    renderTasks();
}

function renderTasks() {
    taskList.innerHTML = '';
    for (let i = 0; i < tasks.length; i++) {
        let task = tasks[i];
        let li = document.createElement('li');
        li.innerHTML = `
            <span>${task}</span>
            <button onclick="editTask(${i}, prompt('Edit task:'))">Edit</button>
            <button onclick="deleteTask(${i})">Delete</button>
        `;
        taskList.appendChild(li);
    }
}

function kevin() {
    const task = taskInput.value;
    if (task) {
        addTask(task);
        taskInput.value = '';
    }
}
//})