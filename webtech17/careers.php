<?php
extract($_GET);
$servername = "localhost";
$dbname = "careers";

// Create connection
if(preg_match('/^[a-zA-Z]+$/',$first) && preg_match('/^[a-zA-Z]+$/',$last) && preg_match('/^[a-z A-Z]+$/',$ad) &&  preg_match('/^[0-9]{10}/',$mob))
{
$conn = new mysqli($servername,"root","",$dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}



$sql = "INSERT INTO career VALUES('$first', '$last','$ad','$em','$mob','$age')";



if ($conn->query($sql) === TRUE) {
    header("location:redirect.html");
} else {
  header("location:redirect_error.html");
}

$conn->close();
}
else {
  {
    header("location:redirect_error.html");
  }
}
?>
