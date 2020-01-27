<?php

include 'bdd.php';

$result=array();

function if0null($x){
  if($x==0){
    return null;
  }
  else{
    return $x;
  }
}

// LangueM
$langueM = $dbh->query("SELECT langueM, COUNT(*) AS nb FROM utilisateur GROUP BY langueM ORDER BY langueM");
$table_langueM = $langueM->fetchAll(PDO::FETCH_OBJ);
$langueM_OUI = null;
$langueM_NON = null;
for ($i=0; $i<count($table_langueM); $i++){
if($table_langueM[$i]->langueM == 'oui')
  $langueM_OUI = $table_langueM[$i]->nb;
else if($table_langueM[$i]->langueM == 'non')
  $langueM_NON = $table_langueM[$i]->nb;
}
array_push($result,array([$langueM_OUI,$langueM_NON]));

// Statut
$statut = $dbh->query("SELECT statut, COUNT(*) AS nb FROM utilisateur GROUP BY statut ORDER BY statut");
$table_statut = $statut->fetchAll(PDO::FETCH_OBJ);
$statut_ETUDIANT = null;
$statut_ENSEIGNANT = null;
$statut_AUTRE = null;
for ($i=0; $i<count($table_statut); $i++){
if($table_statut[$i]->statut == 'etudiant')
  $statut_ETUDIANT = $table_statut[$i]->nb;
else if($table_statut[$i]->statut == 'enseignant')
  $statut_ENSEIGNANT = $table_statut[$i]->nb;
else if($table_statut[$i]->statut == 'autre')
  $statut_AUTRE = $table_statut[$i]->nb;
}
array_push($result,array([$statut_ETUDIANT,$statut_ENSEIGNANT,$statut_AUTRE]));

// Secteur
$secteur = $dbh->query("SELECT secteur, COUNT(*) AS nb FROM utilisateur GROUP BY secteur ORDER BY secteur");
$table_secteur = $secteur->fetchAll(PDO::FETCH_OBJ);
$secteur_ART = null;
$secteur_DROIT = null;
$secteur_ECONOMIE = null;
$secteur_LETTRES = null;
$secteur_SANTE = null;
$secteur_SCIENCESA = null;
$secteur_SCIENCESH = null;
$secteur_AUTRE = null;
for ($i=0; $i<count($table_secteur); $i++){
if($table_secteur[$i]->secteur == 'art')
  $secteur_ART = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'droit')
  $secteur_DROIT = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'economie')
  $secteur_ECONOMIE = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'lettres')
  $secteur_LETTRES = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'sante')
  $secteur_SANTE = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'sciencesA')
  $secteur_SCIENCESA = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'sciencesH')
  $secteur_SCIENCESH = $table_secteur[$i]->nb;
else if($table_secteur[$i]->secteur == 'autre')
  $secteur_AUTRE = $table_secteur[$i]->nb;
}
array_push($result,array([$secteur_ART,$secteur_DROIT,$secteur_ECONOMIE,$secteur_LETTRES,$secteur_SANTE,$secteur_SCIENCESA,$secteur_SCIENCESH,$secteur_AUTRE]));

// Email
$email = $dbh->query("SELECT email FROM utilisateur");
$table_email = $email->fetchAll(PDO::FETCH_OBJ);
$email_OUI = null;
$email_NON = null;
for ($i=0; $i<count($table_email); $i++){
if($table_email[$i]->email != ''){
  if($email_OUI == null){
    $email_OUI = 1;
  }
  else {
    $email_OUI++;
  }
}
else{
  if($email_NON == null){
    $email_NON = 1;
  }
  else {
    $email_NON++;
  }
}
}
array_push($result,array([$email_OUI,$email_NON]));

// Table
function nb($q,$p,$l){
	include 'bdd.php';
	$nb = $dbh->query("SELECT COUNT(*) AS nb FROM utilisateur WHERE ".$q."_".$p."='".$l."'");
	$table_nb = $nb->fetchAll(PDO::FETCH_OBJ);
	return if0null($table_nb[0]->nb);
}

$o1=array([nb(1,1,'o'),nb(2,1,'o'),nb(3,1,'o'),nb(4,1,'o'),nb(5,1,'o'),nb(6,1,'o'),nb(7,1,'o'),nb(8,1,'o'),nb(9,1,'o'),nb(10,1,'o'),nb(11,1,'o'),nb(12,1,'o')]);
array_push($result,$o1);

$p1=array([nb(1,1,'p'),nb(2,1,'p'),nb(3,1,'p'),nb(4,1,'p'),nb(5,1,'p'),nb(6,1,'p'),nb(7,1,'p'),nb(8,1,'p'),nb(9,1,'p'),nb(10,1,'p'),nb(11,1,'p'),nb(12,1,'p')]);
array_push($result,$p1);

$n1=array([nb(1,1,'n'),nb(2,1,'n'),nb(3,1,'n'),nb(4,1,'n'),nb(5,1,'n'),nb(6,1,'n'),nb(7,1,'n'),nb(8,1,'n'),nb(9,1,'n'),nb(10,1,'n'),nb(11,1,'n'),nb(12,1,'n')]);
array_push($result,$n1);


$o2=array([nb(1,2,'o'),nb(2,2,'o'),nb(3,2,'o'),nb(4,2,'o'),nb(5,2,'o'),nb(6,2,'o'),nb(7,2,'o'),nb(8,2,'o'),nb(9,2,'o'),nb(10,2,'o'),nb(11,2,'o'),nb(12,2,'o')]);
array_push($result,$o2);

$p2=array([nb(1,2,'p'),nb(2,2,'p'),nb(3,2,'p'),nb(4,2,'p'),nb(5,2,'p'),nb(6,2,'p'),nb(7,2,'p'),nb(8,2,'p'),nb(9,2,'p'),nb(10,2,'p'),nb(11,2,'p'),nb(12,2,'p')]);
array_push($result,$p2);

$n2=array([nb(1,2,'n'),nb(2,2,'n'),nb(3,2,'n'),nb(4,2,'n'),nb(5,2,'n'),nb(6,2,'n'),nb(7,2,'n'),nb(8,2,'n'),nb(9,2,'n'),nb(10,2,'n'),nb(11,2,'n'),nb(12,2,'n')]);
array_push($result,$n2);


$o3=array([nb(1,3,'o'),nb(2,3,'o'),null,nb(4,3,'o'),nb(5,3,'o'),null,nb(7,3,'o'),null,nb(9,3,'o'),nb(10,3,'o'),null,nb(12,3,'o')]);
array_push($result,$o3);

$p3=array([nb(1,3,'p'),nb(2,3,'p'),null,nb(4,3,'p'),nb(5,3,'p'),null,nb(7,3,'p'),null,nb(9,3,'p'),nb(10,3,'p'),null,nb(12,3,'p')]);
array_push($result,$p3);

$n3=array([nb(1,3,'n'),nb(2,3,'n'),null,nb(4,3,'n'),nb(5,3,'n'),null,nb(7,3,'n'),null,nb(9,3,'n'),nb(10,3,'n'),null,nb(12,3,'n')]);
array_push($result,$n3);


$o4=array([null,null,null,null,null,null,null,null,null,nb(10,4,'o'),null,null]);
array_push($result,$o4);

$p4=array([null,null,null,null,null,null,null,null,null,nb(10,4,'p'),null,null]);
array_push($result,$p4);

$n4=array([null,null,null,null,null,null,null,null,null,nb(10,4,'n'),null,null]);
array_push($result,$n4);


// Moyenne temps

function t($q,$p){
  include 'bdd.php';
  $t = $dbh->query("SELECT AVG(t".$q."_".$p.") AS t FROM utilisateur");
  $table_t = $t->fetchAll(PDO::FETCH_OBJ);
  return round($table_t[0]->t,3);
}

function t0($q){
  include 'bdd.php';
  $t = $dbh->query("SELECT AVG(t".$q.") AS t FROM utilisateur");
  $table_t = $t->fetchAll(PDO::FETCH_OBJ);
  return round($table_t[0]->t,3);
}

$t0=array([
  t0(1)-t(1,1)-t(1,2)-t(1,3),
  t0(2)-t(2,1)-t(2,2)-t(2,3),
  t0(3)-t(3,1)-t(3,2),
  t0(4)-t(4,1)-t(4,2)-t(4,3),
  t0(5)-t(5,1)-t(5,2)-t(5,3),
  t0(6)-t(6,1)-t(6,2),
  t0(7)-t(7,1)-t(7,2)-t(7,3),
  t0(8)-t(8,1)-t(8,2),
  t0(9)-t(9,1)-t(9,2)-t(9,3),
  t0(10)-t(10,1)-t(10,2)-t(10,3)-t(10,4),
  t0(11)-t(11,1)-t(11,2),
  t0(12)-t(12,1)-t(12,2)-t(12,3)
]);



$t1=array([t(1,1),t(2,1),t(3,1),t(4,1),t(5,1),t(6,1),t(7,1),t(8,1),t(9,1),t(10,1),t(11,1),t(12,1)]);
$t2=array([t(1,2),t(2,2),t(3,2),t(4,2),t(5,2),t(6,2),t(7,2),t(8,2),t(9,2),t(10,2),t(11,2),t(12,2)]);
$t3=array([t(1,3),t(2,3),null,t(4,3),t(5,3),null,t(7,3),null,t(9,3),t(10,3),null,t(12,3)]);
$t4=array([null,null,null,null,null,null,null,null,null,t(10,4),null,null]);

array_push($result,$t0);
array_push($result,$t1);
array_push($result,$t2);
array_push($result,$t3);
array_push($result,$t4);

// Nombre de phrases par sens
function val($q,$r){
  include 'bdd.php';
  $val = $dbh->query("SELECT ".$q."_".$r." AS val FROM utilisateur");
  $table_val = $val->fetchAll(PDO::FETCH_OBJ);
  return($table_val[0]->val);
}

function nb2($q,$p,$l){
  include 'bdd.php';
  $nb = $dbh->query("SELECT COUNT(*) AS nb FROM utilisateur WHERE ".$q."_".$p."='".$l."'");
  $table_nb = $nb->fetchAll(PDO::FETCH_OBJ);
  return $table_nb[0]->nb;
}

$nb_o=nb2(1,1,'o')+nb2(1,2,'o')+nb2(1,3,'o')+nb2(2,1,'o')+nb2(2,2,'o')+nb2(2,3,'o')+nb2(3,1,'o')+nb2(3,2,'o')+nb2(4,1,'o')+nb2(4,2,'o')+nb2(4,3,'o')+nb2(5,1,'o')+nb2(5,2,'o')+nb2(5,3,'o')+nb2(6,1,'o')+nb2(6,2,'o')+nb2(7,1,'o')+nb2(7,2,'o')+nb2(7,3,'o')+nb2(8,1,'o')+nb2(8,2,'o')+nb2(9,1,'o')+nb2(9,2,'o')+nb2(9,3,'o')+nb2(10,1,'o')+nb2(10,2,'o')+nb2(10,3,'o')+nb2(10,4,'o')+nb2(11,1,'o')+nb2(11,2,'o')+nb2(12,1,'o')+nb2(12,2,'o')+nb2(12,3,'o');

$nb_p=nb2(1,1,'p')+nb2(1,2,'p')+nb2(1,3,'p')+nb2(2,1,'p')+nb2(2,2,'p')+nb2(2,3,'p')+nb2(3,1,'p')+nb2(3,2,'p')+nb2(4,1,'p')+nb2(4,2,'p')+nb2(4,3,'p')+nb2(5,1,'p')+nb2(5,2,'p')+nb2(5,3,'p')+nb2(6,1,'p')+nb2(6,2,'p')+nb2(7,1,'p')+nb2(7,2,'p')+nb2(7,3,'p')+nb2(8,1,'p')+nb2(8,2,'p')+nb2(9,1,'p')+nb2(9,2,'p')+nb2(9,3,'p')+nb2(10,1,'p')+nb2(10,2,'p')+nb2(10,3,'p')+nb2(10,4,'p')+nb2(11,1,'p')+nb2(11,2,'p')+nb2(12,1,'p')+nb2(12,2,'p')+nb2(12,3,'p');

$nb_n=nb2(1,1,'n')+nb2(1,2,'n')+nb2(1,3,'n')+nb2(2,1,'n')+nb2(2,2,'n')+nb2(2,3,'n')+nb2(3,1,'n')+nb2(3,2,'n')+nb2(4,1,'n')+nb2(4,2,'n')+nb2(4,3,'n')+nb2(5,1,'n')+nb2(5,2,'n')+nb2(5,3,'n')+nb2(6,1,'n')+nb2(6,2,'n')+nb2(7,1,'n')+nb2(7,2,'n')+nb2(7,3,'n')+nb2(8,1,'n')+nb2(8,2,'n')+nb2(9,1,'n')+nb2(9,2,'n')+nb2(9,3,'n')+nb2(10,1,'n')+nb2(10,2,'n')+nb2(10,3,'n')+nb2(10,4,'n')+nb2(11,1,'n')+nb2(11,2,'n')+nb2(12,1,'n')+nb2(12,2,'n')+nb2(12,3,'n');

$nb=array([if0null($nb_o),if0null($nb_p),if0null($nb_n)]);
array_push($result,$nb);


// Temps de réflexion moyen par sens
function sumT($q,$p,$l){
  include 'bdd.php';
  $t = $dbh->query("SELECT SUM(t".$q."_".$p.") AS t FROM utilisateur WHERE ".$q."_".$p."='".$l."'");
  $table_t = $t->fetchAll(PDO::FETCH_OBJ);
  return $table_t[0]->t;
}

function moy($sum,$nb){
  if($nb==0){
    return null;
  }
  else{
    return round($sum/$nb,3);
  }
}

$sumT_o=sumT(1,1,'o')+sumT(1,2,'o')+sumT(1,3,'o')+sumT(2,1,'o')+sumT(2,2,'o')+sumT(2,3,'o')+sumT(3,1,'o')+sumT(3,2,'o')+sumT(4,1,'o')+sumT(4,2,'o')+sumT(4,3,'o')+sumT(5,1,'o')+sumT(5,2,'o')+sumT(5,3,'o')+sumT(6,1,'o')+sumT(6,2,'o')+sumT(7,1,'o')+sumT(7,2,'o')+sumT(7,3,'o')+sumT(8,1,'o')+sumT(8,2,'o')+sumT(9,1,'o')+sumT(9,2,'o')+sumT(9,3,'o')+sumT(10,1,'o')+sumT(10,2,'o')+sumT(10,3,'o')+sumT(10,4,'o')+sumT(11,1,'o')+sumT(11,2,'o')+sumT(12,1,'o')+sumT(12,2,'o')+sumT(12,3,'o');

$sumT_p=sumT(1,1,'p')+sumT(1,2,'p')+sumT(1,3,'p')+sumT(2,1,'p')+sumT(2,2,'p')+sumT(2,3,'p')+sumT(3,1,'p')+sumT(3,2,'p')+sumT(4,1,'p')+sumT(4,2,'p')+sumT(4,3,'p')+sumT(5,1,'p')+sumT(5,2,'p')+sumT(5,3,'p')+sumT(6,1,'p')+sumT(6,2,'p')+sumT(7,1,'p')+sumT(7,2,'p')+sumT(7,3,'p')+sumT(8,1,'p')+sumT(8,2,'p')+sumT(9,1,'p')+sumT(9,2,'p')+sumT(9,3,'p')+sumT(10,1,'p')+sumT(10,2,'p')+sumT(10,3,'p')+sumT(10,4,'p')+sumT(11,1,'p')+sumT(11,2,'p')+sumT(12,1,'p')+sumT(12,2,'p')+sumT(12,3,'p');

$sumT_n=sumT(1,1,'n')+sumT(1,2,'n')+sumT(1,3,'n')+sumT(2,1,'n')+sumT(2,2,'n')+sumT(2,3,'n')+sumT(3,1,'n')+sumT(3,2,'n')+sumT(4,1,'n')+sumT(4,2,'n')+sumT(4,3,'n')+sumT(5,1,'n')+sumT(5,2,'n')+sumT(5,3,'n')+sumT(6,1,'n')+sumT(6,2,'n')+sumT(7,1,'n')+sumT(7,2,'n')+sumT(7,3,'n')+sumT(8,1,'n')+sumT(8,2,'n')+sumT(9,1,'n')+sumT(9,2,'n')+sumT(9,3,'n')+sumT(10,1,'n')+sumT(10,2,'n')+sumT(10,3,'n')+sumT(10,4,'n')+sumT(11,1,'n')+sumT(11,2,'n')+sumT(12,1,'n')+sumT(12,2,'n')+sumT(12,3,'n');


$moy=array([moy($sumT_o,$nb_o),moy($sumT_p,$nb_p),moy($sumT_n,$nb_n)]);
array_push($result,$moy);

// Temps de lecture de la question en fonction de l'ordre
function tOrdreQ($ordre){
  include 'bdd.php';
  $t=0;
  $o = $dbh->query("SELECT id,o".$ordre." AS idQ FROM utilisateur");
  $table_o = $o->fetchAll(PDO::FETCH_OBJ);
  for($i=0; $i<sizeof($table_o); $i++){
    include 'bdd.php';
    $o2 = $dbh->query("SELECT tq".$table_o[$i]->idQ." AS t FROM utilisateur WHERE id=".$table_o[$i]->id);
    $table_o2 = $o2->fetchAll(PDO::FETCH_OBJ);
    $t+=$table_o2[0]->t;
  }
  return round($t/sizeof($table_o),3);
}

$tOrdreQ=array([tOrdreQ(1),tOrdreQ(2),tOrdreQ(3),tOrdreQ(4),tOrdreQ(5),tOrdreQ(6),tOrdreQ(7),tOrdreQ(8),tOrdreQ(9),tOrdreQ(10),tOrdreQ(11),tOrdreQ(12)]);

array_push($result,$tOrdreQ);

// Temps de réponse moyen en fonction de l'ordre de la question
function tOrdreR($ordre){
  include 'bdd.php';
  $t=0;
  $o = $dbh->query("SELECT id,o".$ordre." AS idQ FROM utilisateur");
  $table_o = $o->fetchAll(PDO::FETCH_OBJ);
  for($i=0; $i<sizeof($table_o); $i++){
    include 'bdd.php';
    $o2 = $dbh->query("SELECT tr".$table_o[$i]->idQ." AS t FROM utilisateur WHERE id=".$table_o[$i]->id);
    $table_o2 = $o2->fetchAll(PDO::FETCH_OBJ);
    $t+=$table_o2[0]->t;
  }
  return round($t/sizeof($table_o),3);
}

$tOrdreR=array([tOrdreR(1),tOrdreR(2),tOrdreR(3),tOrdreR(4),tOrdreR(5),tOrdreR(6),tOrdreR(7),tOrdreR(8),tOrdreR(9),tOrdreR(10),tOrdreR(11),tOrdreR(12)]);

array_push($result,$tOrdreR);

// ENVOI
echo json_encode($result);

?>