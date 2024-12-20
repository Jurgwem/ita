document.addEventListener("keydown", fullscreen)


function fullscreen(e) {
    if (e.key == "Enter") {
        toggleFullScreen();
    }
}

function toggleFullScreen() {
    if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen();
    } else if (document.exitFullscreen) {
      document.exitFullscreen();
    }
  }