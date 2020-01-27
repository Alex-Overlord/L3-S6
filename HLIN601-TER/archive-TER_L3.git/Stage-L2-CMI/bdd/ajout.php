<?php
include("connexion.php");
connexion();
$sql = "INSERT INTO mabase(Q1,Q2,Q3,Q5) ";
$sql .= "VALUES('','".$_POST['Q1']."','".$_POST['Q2']."','".$_POST['Q3']."','".$_POST['Q4']."','".$_POST['Q5']."')";
    
mysql_query($sql) or die(mysql_error());
?>