<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>RÉSULTATS - Étude des préférences dans l’expression de la quantification</title>
    
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    
    <link rel="shortcut icon" href="images/favicon.ico" type="image/x-icon">
    <link rel="icon" href="images/favicon.ico" type="image/x-icon">
    
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700,800&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Prata&display=swap" rel="stylesheet">

    <link rel="stylesheet" href="css/open-iconic-bootstrap.min.css">
    <link rel="stylesheet" href="css/animate.css">  
    <link rel="stylesheet" href="css/owl.carousel.min.css">
    <link rel="stylesheet" href="css/owl.theme.default.min.css">
    <link rel="stylesheet" href="css/magnific-popup.css">
    <link rel="stylesheet" href="css/aos.css">
    <link rel="stylesheet" href="css/ionicons.min.css">	
    <link rel="stylesheet" href="css/bootstrap-datetimepicker.min.css">
    <link rel="stylesheet" href="css/nouislider.css">  
    <link rel="stylesheet" href="css/flaticon.css">
    <link rel="stylesheet" href="css/icomoon.css">
    <link rel="stylesheet" href="css/style.css">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

  </head>
  <body> 
		
  <div class="main-section">

		<nav class="navbar navbar-expand-lg navbar-dark ftco_navbar bg-dark ftco-navbar-light" id="ftco-navbar">
	    <div class="container">
	      <a class="navbar-brand" href="">RÉSULTATS - Étude des préférences dans l’expression de la quantification</a>
	    </div>
	  </nav>
    <!-- END nav -->

  	<section class="hero-wrap fondvert js-fullheight">
  		<div class="container">
  			<div class="row description js-fullheight align-items-center justify-content-center">
  				<div class="col-md-8 text-center">
  					<div class="text">
  						<h1>TER L3</h1>
  						<h3 class="mb-5" style="color: white;"><b>RÉSULTATS - Étude des préférences dans l’expression de la quantification</b></h3>
  						<p><a href="https://gitlab.info-ufr.univ-montp2.fr/e20170000656/TER_L3" target=_blank class="btn btn-white px-4 py-3"><i class="ion-ios-open mr-2"></i>Voir le code source</a></p>
              <p><a href="images/Rapport TERL3.pdf" target=_blank class="btn btn-white px-4 py-3"><i class="ion-ios-download mr-2"></i>Télécharger le rapport</a></p>
  						<p><a href="index.php" class="btn btn-white px-4 py-3"><i class="ion-ios-redo mr-2"></i>Refaire le questionnaire</a></p>
  					</div>
  				</div>
  			</div>
  		</div>
  	</section>

  	<section class="ftco-section" id="navigationTabs">

    <div class="wrapper">
    	<div class="container d-flex flex-column justify-content-center align-items-center">
      	<div class="title text-center mb-4">
        	<h2>Le français est-il votre langue maternelle ?</h2>
      	</div>
      	<div class="chart-wrapper">
        	<canvas id="langueM"></canvas>
      	</div>
    	</div>
    </div>
    
    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-4">
          <h2>Quel est votre statut ?</h2>
        </div>
        <div class="chart-wrapper">
          <canvas id="statut"></canvas>
        </div>
      </div>
    </div>

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-4">
          <h2>Quel est votre secteur d'activité ou d'étude ?</h2>
        </div>
        <div class="chart-wrapper">
          <canvas id="secteur"></canvas>
        </div>
      </div>
    </div>

    <!--<div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-6">
          <h2>L'adresse mail est-elle renseignée ?</h2>
        </div>
        <div class="chart-wrapper">
          <canvas id="email"></canvas>
        </div>
      </div>
    </div>-->

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-1">
          <h2>Les propositions ont-elles le même sens que la phrase ?</h2>
        </div>
        <div class="chart-wrapperG">
          <canvas id="reponses"></canvas>
        </div>
      </div>
    </div>

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-1">
          <h2>Temps de réflexion moyen par phrase (en secondes)</h2>
        </div>
        <div class="chart-wrapperG">
          <canvas id="tempsQ"></canvas>
        </div>
      </div>
    </div>

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-1">
          <h2>Nombre de réponses par sens donné aux propositions</h2>
        </div>
        <div class="chart-wrapperM">
          <canvas id="nbSens"></canvas>
        </div>
      </div>
    </div>

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-1">
          <h2>Temps de réflexion moyen par sens donné aux propositions (en secondes)</h2>
        </div>
        <div class="chart-wrapperM">
          <canvas id="tempsQ2"></canvas>
        </div>
      </div>
    </div>

    <div class="wrapper">
      <div class="container d-flex flex-column justify-content-center align-items-center">
        <div class="title text-center mb-1">
          <h2>Temps de réflexion moyen par propositions (en secondes) en fonction de l'ordre dans lequel les questions sont abordées</h2>
        </div>
        <div class="chart-wrapperM">
          <canvas id="tempsOrdre"></canvas>
        </div>
      </div>
    </div>

	</section>
	  <!-- - - - - -end- - - - -  -->

	  <div class="text-center">
		<section class="ftco-section ftco-section-2 bg-light" id="cards">
			<div id="questionsFinales" class="container container2">
				<div class="title text-center mb-4">
		          <h2>Table des données</h2>
		        </div>
				<table class="table table-striped">
				  <thead>
				    <tr>
				      <th scope="col">#</th>
				      <th scope="col">Date d'envoi</th>
				      <th scope="col">Français</th>
				      <th scope="col">Statut</th>
				      <th scope="col">Secteur</th>
				      <!--<th scope="col">E-mail</th>-->
				      <th scope="col">P1</th>
				      <th scope="col">P2</th>
				      <th scope="col">P3</th>
				      <th scope="col">P4</th>
				      <th scope="col">P5</th>
				      <th scope="col">P6</th>
				      <th scope="col">P7</th>
				      <th scope="col">P8</th>
				      <th scope="col">P9</th>
				      <th scope="col">P10</th>
				      <th scope="col">P11</th>
				      <th scope="col">P12</th>
				    </tr>
				  </thead>
				  <tbody>
				    <?php include 'tableau.php'; ?>
				  </tbody>
				</table>
			</div>
	  	</section>
	  <!-- - - - - -end- - - - -  -->

	  </div>


	  <footer class="ftco-section ftco-section-2">
	  	<div class="col-md-12 text-center">
          <p class="mb-0">
            Copyright &copy;<script>document.write(new Date().getFullYear());</script> | TER L3 - Étude des préférences dans l’expression de la quantification<br><br>
            <b>Dernière mise à jour : 31/12/2019 à 23:00</b>
          </p>
        </div>
	  </footer>
  </div>

  <!-- loader -->
  <div id="ftco-loader" class="show fullscreen"><svg class="circular" width="48px" height="48px"><circle class="path-bg" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke="#eeeeee"/><circle class="path" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke-miterlimit="10" stroke="#F96D00"/></svg></div>

  <script src="js/jquery.min.js"></script>
  <script src="js/jquery-migrate-3.0.1.min.js"></script>
  <script src="js/popper.min.js"></script>
  <script src="js/bootstrap.min.js"></script>
  <script src="js/jquery.easing.1.3.js"></script>
  <script src="js/jquery.waypoints.min.js"></script>
  <script src="js/jquery.stellar.min.js"></script>
  <script src="js/owl.carousel.min.js"></script>
  <script src="js/jquery.magnific-popup.min.js"></script>
  <script src="js/aos.js"></script>

  <script src="js/nouislider.min.js"></script>
  <script src="js/moment-with-locales.min.js"></script>
  <script src="js/bootstrap-datetimepicker.min.js"></script>
  <script src="js/main.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.7.3/Chart.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/chartjs-plugin-datalabels"></script>
  <script type="text/javascript" src="resultats.js"></script> 

  </body>
</html>