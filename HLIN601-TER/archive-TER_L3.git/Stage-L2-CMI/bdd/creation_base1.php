<?php
include("connexion.php");
 
connexion();
 
$sql= "CREATE TABLE IF NOT EXISTS 'mabase' ";

$sql .= "`Q1` text NOT NULL,";
$sql .= "`Q2` text NOT NULL,";
$sql .= "`Q3` text NOT NULL,";
$sql .= "`Q4` text NOT NULL,";
$sql .= "`Q5` text NOT NULL,";
$sql .= "`Q6` text NOT NULL,";
$sql .= "`Q7` text NOT NULL,";
$sql .= "`Q8` text NOT NULL,";
$sql .= "`Q9` text NOT NULL,";
$sql .= "`Q10` text NOT NULL,";
$sql .= "`Q11` text NOT NULL,";
$sql .= "`Q12` text NOT NULL,";
$sql .= "`Q13` text NOT NULL,";


$sql .= ") ENGINE=MyISAM;";
 
mysql_query($sql) or die(mysql_error());
?>