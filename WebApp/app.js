/****
 * AJAX function prompts user to enter access token and device id
 * sets appropriate headder vaules
 * triggers a post request and displays status on web page
 */

function sendMessageFunction(){
    $("#Response").html("Sending Your Messages");
    let access_token = prompt("Enter Access Token");
    console.log(access_token);
    let device_ID = prompt("Enter Device ID");
    console.log(device_ID);
    $.ajax({
                type : 'POST',
                url : "https://api.particle.io/v1/devices/"+device_ID+"/PlayMorseCode",
                headers : {
                    Authorization : 'Bearer ' + access_token
                },
                contentType : 'application/x-www-form-urlencoded',
                data : {args : $("#args").val()},
                success : function(response) {
                    $("#Response").html("Your Message has been Sent");
                    console.log(response);
                },
                error : function(xhr, status, error) {
                    var err = eval("(" + xhr.responseText + ")");
                    $("#Response").html("ERROR Sending your mesaage"+err.responseText);
                    console.log(err);                   
                }
            }); 
    } 
