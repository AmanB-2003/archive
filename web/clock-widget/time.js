setInterval(showTime,2000);   //update after every 2s

function showTime() {
    let time = new Date();
    let hour = time.getHours();
    let min = time.getMinutes();

    hour = hour < 10 ? "0" + hour : hour ;
    min = min < 10 ? "0" + min : min ;

    let currentTime = hour + " : " + min;

    //update innerHTML
    document.getElementById("time").innerHTML = currentTime; 
}

//call function
showTime();

