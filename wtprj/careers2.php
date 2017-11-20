<?php
extract($_GET);
$servername = "localhost";
$dbname = "careers";

// Create connection
$conn = new mysqli($servername,"root","",$dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 



$sql = "INSERT INTO donations VALUES('$Fname', '$Lname','$email','$mobile','$mon')";

 

if ($conn->query($sql) === TRUE) {
    echo 'created successfully';
} else {
    echo 'Error:' . $sql . '<br>' . $conn->error;
}

$conn->close();

?>