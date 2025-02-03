const loginForm = document.getElementById("adminlogin");
const loginButton = document.getElementById("login-form-submit");
const loginErrorMsg = document.getElementById("login-error-msg");
const panel = document.getElementById("adminpanel");

loginButton.addEventListener("click", (e) => {
    e.preventDefault();
    const username = loginForm.username.value;
    const password = loginForm.password.value;

    if (username === "admin" && password === "admin") 
    {
        window.location.replace('../html/panel.html');
    } 
    else 
    {
        loginErrorMsg.style.opacity = 1;
    }
}
)