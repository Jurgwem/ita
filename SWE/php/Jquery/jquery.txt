$(document).ready(jquery);


function jquery() {
    $(".showall").click(function() {
        $("p").show();
    });

    $(".hideall").click(function() {
        $("p").hide();
    });

    $(".fadeallin").click(function() {
        $("p").fadeIn();
    });

    $(".fadeallout").click(function() {
        $("p").fadeOut();
    });

    $(".slidealldown").click(function() {
        $("p").slideDown();
    });

    $(".slideallup").click(function() {
        $("p").slideUp();
    });

    $("p").click(function() {
        $(this).hide();
    });
}