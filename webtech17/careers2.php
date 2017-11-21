<?php
extract($_GET);
$servername = "localhost";
$dbname = "careers";

// Create connection
if(preg_match('/^[a-zA-Z]+$/',$Fname) && preg_match('/^[a-zA-Z]+$/',$Lname) && preg_match('/^[0-9]+$/',$mon) && preg_match('/^[0-9]{10}/',$mobile)  && preg_match('/^[a-z A-Z]+$/',$Chname) && strlen($ccname)==16 )
{
$conn = new mysqli($servername,"root","",$dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}



$sql = "INSERT INTO donations VALUES('$Fname', '$Lname','$email','$mobile','$mon')";



if ($conn->query($sql) === TRUE) {
    header("location:redirect.html");
} else {

    header("location:redirect_error1.html");
}

$conn->close();
}
else {
  header("location:redirect_error1.html");
}
?>
