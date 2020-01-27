function Shuffle(o) {
	for(var j, x, i = o.length; i; j = parseInt(Math.random() * i), x = o[--i], o[i] = o[j], o[j] = x);
	return o;
};

var donnees;

$.getJSON("questions.json",function(data){
	donnees = Shuffle(data);
	$.each(donnees, function(i,json){
		json.reponses = Shuffle(json.reponses);
	});
});

var debutQ;
var debutR;

// Début du quizz
document.getElementById("lancement").onclick = function(){
	console.log("Lancement");
	document.getElementById("lancement").remove();
	document.getElementById("navigationTabs").remove();
	$.each(donnees, function(i,json){
		$("#questionnaire").append("<div class='block'><div id='q"+i+"' class='blockquote mb-5'>"+
			"<small>Phrase n°"+(i+1)+"/12</small><br><b>"+json.question+"</b><br><button class='btn btn-outline-secondary' id='bouton' value='"+i+"' onClick='q1(this)'>Voir les propositions</button><br>");
		for(var indexq=0; indexq<json.nb; indexq++){
			$("#q"+i).append("<div id='q"+i+"r"+indexq+"' style='text-align: center;'>"+json.reponses[indexq].r+"<br>"+
				"<div style='text-align: center;' class='btn-group-toggle' data-toggle='buttons'>"+
				"<label onClick='q(this)' idq="+json.id+" idr="+json.reponses[indexq].idr+" q="+i+" r="+indexq+" value='o' class='btn btn-outline-success'>"+
				"<input type='radio' autocomplete='off'>OUI</label>"+
				"<label onClick='q(this)' idq="+json.id+" idr="+json.reponses[indexq].idr+" q="+i+" r="+indexq+" value='p' class='btn btn-outline-primary'>"+
				"<input type='radio' autocomplete='off'>PEUT-ÊTRE</label>"+
				"<label onClick='q(this)' idq="+json.id+" idr="+json.reponses[indexq].idr+" q="+i+" r="+indexq+" value='n' class='btn btn-outline-danger'>"+
				"<input type='radio' autocomplete='off'>NON</label>"+
				"</div><br></div>");
			$("#q"+i+"r"+indexq).hide();
		}
		if(i!=0){
			$("#q"+i).hide();
		}
	});
	debutQ = Date.now();
};

// Affiche la première question
function q1(objet){
	var i = objet.value;
	objet.remove();
	$("#q"+i+"r0").show();
	debutR = Date.now();
}

var reponses = [
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
];

var idreponses = [
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
];

var idquestions = [null, null, null, null, null, null, null, null, null, null, null, null];

var tq = [null, null, null, null, null, null, null, null, null, null, null, null];

var tr = [
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
[null, null, null, null],
];

// Affiche les autres questions
function q(objet){
    var q = objet.getAttribute("q");
    var r = objet.getAttribute("r");
    var id = objet.getAttribute("idq");
    idquestions[q] = id;
    var id2 = objet.getAttribute("idr");
    idreponses[id-1][r] = id2;
    var val = objet.getAttribute("value");
    reponses[id-1][id2-1] = val;

    var tR = (Date.now()-debutR)/1000;
    tr[id-1][id2-1] = tR;

    console.log("val="+val+" q"+q+"r"+r+" idq="+id+" idr="+id2+" t="+tR);

    $("#q"+q+"r"+r).hide();
	var nb = donnees[q].reponses.length;
	if((nb-1)!=r){
		var Rsuivant = parseInt(r,10)+1;
		$("#q"+q+"r"+Rsuivant).show();
		debutR = Date.now();
	}
	else{
		var Qsuivant = parseInt(q,10)+1;
		$("#q"+q).hide();

		var tQ = (Date.now()-debutQ)/1000;
		console.log("T(Q"+id+") = "+tQ);
		tq[id-1]=tQ;

		if(Qsuivant==12){
			$("#questionnaire").remove();
			$("#cards").show();
		}
		else{
			$("#q"+Qsuivant).show();
			debutQ = Date.now();
		}
	}
};

// A une valeur ?
function isset(ref) { 
	return $("input:radio[name="+ref+"]:checked").val() != null;
}

// A comme valeur val ?
function isnotval(ref, val) { 
  return $("input:radio[name="+ref+"]:checked").val() != val;
}

// Valeur
function val(ref) { 
  return $("input:radio[name="+ref+"]:checked").val();
}

// Supprimer()
function suppr(ref) {
	var elements = document.getElementsByClassName("alert");
  	if(elements.length > 0){
  		elements[0].remove();
  	}
}

function r(q,r){
	return reponses[q-1][r-1];
}

function o(q,r){
	return idreponses[q-1][r-1];
}

function t(q,r){
	return tr[q-1][r-1];
}

/*function mailOK() 
{
	/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(document.getElementById("email").value);
}*/

// Si bouton submit cliqué
document.getElementById("submit").onclick = function(event){
    // Vérification hack formulaire
    var hackLangue = isnotval("langueM","oui") && isnotval("langueM","non") && isset("langueM");
    var hackStatut = isnotval("statut","etudiant") && isnotval("statut","enseignant") 
    && isnotval("statut","autre") && isset("statut");
    var hackSecteur = isnotval("secteur","art") && isnotval("secteur","droit") && isnotval("secteur","economie")
    && isnotval("secteur","lettres") && isnotval("secteur","sante") && isnotval("secteur","sciencesA")
    && isnotval("secteur","sciencesH") && isnotval("secteur","autre") && isset("secteur");
    var hack = hackLangue || hackStatut || hackSecteur;
  	
    var vide = !isset("langueM") && !isset("statut") && !isset("secteur");
  	var OK = isset("langueM") && isset("statut") && isset("secteur");
  	suppr("alert");

  	if(vide){
  		$('#questionsFinales').append("<div class='alert alert-danger' style='margin-top:30px;text-align:left;'"+
  			"role='alert'><b>Merci de remplir les champs avant de valider les réponses !</b><br></div>");
  	}
    else if(hack){
      $('#questionsFinales').append("<div class='alert alert-danger' style='margin-top:30px; text-align:left;'"+
        "role='alert'><b>Merci de ne pas hacker ce formulaire !</b><br></div>");
    }
  	else if(!OK){
  		var message = "<div class='alert alert-danger' style='margin-top:30px; text-align:left;'"+
  			"role='alert'><b>Vos réponses n\'ont pas été envoyées car vous n\'avez pas rempli le(s) champ(s) suivant(s) :</b><br>";
  		if(!isset("langueM")){
			message += "- Le français est-il votre langue maternelle ?<br>";
		}
		if(!isset("statut")){
			message += "- Quel est votre statut ?<br>";
		}
		if(!isset("secteur")){
			message += "- Quel est votre secteur d\'activité ou d\'étude ?<br>";
		}
		/*if(!mailOK()){
			message += "<br><b>L'adresse email n'est pas valide</b><br>";
		}*/
		message += "</div>";
		$('#questionsFinales').append(message);
  	}
  	/*else if (!mailOK()){
		$('#questionsFinales').append("<div class='alert alert-danger' style='margin-top:30px; text-align:left;'"+
  			"role='alert'><b>L'adresse email n'est pas valide</b><br>");
  	}*/
  	else{
		console.log(idquestions);
  		console.log(idreponses);
		console.log(reponses);
		console.log(tq);
		console.log(tr);

		var envoi="q1_1="+r(1,1);
		envoi+="&q1_2="+r(1,2);
		envoi+="&q1_3="+r(1,3);

		envoi+="&q2_1="+r(2,1);
		envoi+="&q2_2="+r(2,2);
		envoi+="&q2_3="+r(2,3);

		envoi+="&q3_1="+r(3,1);
		envoi+="&q3_2="+r(3,2);

		envoi+="&q4_1="+r(4,1);
		envoi+="&q4_2="+r(4,2);
		envoi+="&q4_3="+r(4,3);

		envoi+="&q5_1="+r(5,1);
		envoi+="&q5_2="+r(5,2);
		envoi+="&q5_3="+r(5,3);

		envoi+="&q6_1="+r(6,1);
		envoi+="&q6_2="+r(6,2);

		envoi+="&q7_1="+r(7,1);
		envoi+="&q7_2="+r(7,2);
		envoi+="&q7_3="+r(7,3);

		envoi+="&q8_1="+r(8,1);
		envoi+="&q8_2="+r(8,2);

		envoi+="&q9_1="+r(9,1);
		envoi+="&q9_2="+r(9,2);
		envoi+="&q9_3="+r(9,3);

		envoi+="&q10_1="+r(10,1);
		envoi+="&q10_2="+r(10,2);
		envoi+="&q10_3="+r(10,3);
		envoi+="&q10_4="+r(10,4);

		envoi+="&q11_1="+r(11,1);
		envoi+="&q11_2="+r(11,2);

		envoi+="&q12_1="+r(12,1);
		envoi+="&q12_2="+r(12,2);
		envoi+="&q12_3="+r(12,3);

		envoi+="&langueM="+val("langueM");
		envoi+="&statut="+val("statut");
		envoi+="&secteur="+val("secteur");

		envoi+="&o1="+idquestions[0];
		envoi+="&o2="+idquestions[1];
		envoi+="&o3="+idquestions[2];
		envoi+="&o4="+idquestions[3];
		envoi+="&o5="+idquestions[4];
		envoi+="&o6="+idquestions[5];
		envoi+="&o7="+idquestions[6];
		envoi+="&o8="+idquestions[7];
		envoi+="&o9="+idquestions[8];
		envoi+="&o10="+idquestions[9];
		envoi+="&o11="+idquestions[10];
		envoi+="&o12="+idquestions[11];

		envoi+="&o1_1="+o(1,1);
		envoi+="&o1_2="+o(1,2);
		envoi+="&o1_3="+o(1,3);

		envoi+="&o2_1="+o(2,1);
		envoi+="&o2_2="+o(2,2);
		envoi+="&o2_3="+o(2,3);

		envoi+="&o3_1="+o(3,1);
		envoi+="&o3_2="+o(3,2);

		envoi+="&o4_1="+o(4,1);
		envoi+="&o4_2="+o(4,2);
		envoi+="&o4_3="+o(4,3);

		envoi+="&o5_1="+o(5,1);
		envoi+="&o5_2="+o(5,2);
		envoi+="&o5_3="+o(5,3);

		envoi+="&o6_1="+o(6,1);
		envoi+="&o6_2="+o(6,2);

		envoi+="&o7_1="+o(7,1);
		envoi+="&o7_2="+o(7,2);
		envoi+="&o7_3="+o(7,3);

		envoi+="&o8_1="+o(8,1);
		envoi+="&o8_2="+o(8,2);

		envoi+="&o9_1="+o(9,1);
		envoi+="&o9_2="+o(9,2);
		envoi+="&o9_3="+o(9,3);

		envoi+="&o10_1="+o(10,1);
		envoi+="&o10_2="+o(10,2);
		envoi+="&o10_3="+o(10,3);
		envoi+="&o10_4="+o(10,4);

		envoi+="&o11_1="+o(11,1);
		envoi+="&o11_2="+o(11,2);

		envoi+="&o12_1="+o(12,1);
		envoi+="&o12_2="+o(12,2);
		envoi+="&o12_3="+o(12,3);

		envoi+="&t1="+tq[0];
		envoi+="&t2="+tq[1];
		envoi+="&t3="+tq[2];
		envoi+="&t4="+tq[3];
		envoi+="&t5="+tq[4];
		envoi+="&t6="+tq[5];
		envoi+="&t7="+tq[6];
		envoi+="&t8="+tq[7];
		envoi+="&t9="+tq[8];
		envoi+="&t10="+tq[9];
		envoi+="&t11="+tq[10];
		envoi+="&t12="+tq[11];

		envoi+="&t1_1="+t(1,1);
		envoi+="&t1_2="+t(1,2);
		envoi+="&t1_3="+t(1,3);

		envoi+="&t2_1="+t(2,1);
		envoi+="&t2_2="+t(2,2);
		envoi+="&t2_3="+t(2,3);

		envoi+="&t3_1="+t(3,1);
		envoi+="&t3_2="+t(3,2);

		envoi+="&t4_1="+t(4,1);
		envoi+="&t4_2="+t(4,2);
		envoi+="&t4_3="+t(4,3);

		envoi+="&t5_1="+t(5,1);
		envoi+="&t5_2="+t(5,2);
		envoi+="&t5_3="+t(5,3);

		envoi+="&t6_1="+t(6,1);
		envoi+="&t6_2="+t(6,2);

		envoi+="&t7_1="+t(7,1);
		envoi+="&t7_2="+t(7,2);
		envoi+="&t7_3="+t(7,3);

		envoi+="&t8_1="+t(8,1);
		envoi+="&t8_2="+t(8,2);

		envoi+="&t9_1="+t(9,1);
		envoi+="&t9_2="+t(9,2);
		envoi+="&t9_3="+t(9,3);

		envoi+="&t10_1="+t(10,1);
		envoi+="&t10_2="+t(10,2);
		envoi+="&t10_3="+t(10,3);
		envoi+="&t10_4="+t(10,4);

		envoi+="&t11_1="+t(11,1);
		envoi+="&t11_2="+t(11,2);

		envoi+="&t12_1="+t(12,1);
		envoi+="&t12_2="+t(12,2);
		envoi+="&t12_3="+t(12,3);

		document.location.href="envoi.php?"+envoi;
  	}
};

