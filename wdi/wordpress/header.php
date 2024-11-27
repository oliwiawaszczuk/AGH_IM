<!DOCTYPE html>
<html>
<head>
    <title>SkySports</title>
    <link rel="icon" type="image/x-icon" href="http://localhost/wordpress/wp-content/uploads/2024/10/logo.jpg">

    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        body {
            height: 100%;
            display: flex;
            font-family: Arial, sans-serif;
        }
        .container {
            flex: 1;
        }
        header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 10px 20px;
            background-color: #004b87;
            color: white;
        }
        main {
            flex: 1;
            padding: 20px;
        }
        footer {
            background-color: #004b87;
            color: white;
            text-align: center;
            padding: 10px 0;
        }
        .logo-container {
            display: flex;
            align-items: center;
        }
        .logo {
            width: 50px;
            height: auto;
            margin-right: 10px;
        }
        .site-name {
            font-size: 24px;
            font-weight: bold;
        }
        .navigation ul {
            list-style-type: none;
            display: flex;
            gap: 15px;
        }
        a {
            text-decoration: none;
            color: white;
            font-size: 16px;
        }
        main a {
            color: black;
        }
        a:hover {
            text-decoration: underline;
        }
        .post {
            margin: 20px;
            padding: 15px;
            background-color: #f9f9f9;
            border-radius: 8px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        .post h2 {
            color: #004b87;
        }
        .post p {
            line-height: 1.6;
            margin-bottom: 15px;
            color: #333;
        }
        .post ul {
            margin: 10px 0;
            padding-left: 20px;
            color: #333;
        }
        .post li {
            margin-bottom: 5px;
        }
        .post table {
            width: 100%;
            border-collapse: collapse;
        }
        .post th, .post td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        .post th {
            background-color: #004b87;
            color: white;
        }
        #footer-random {
            padding: 20px 0;
            font-family: "Helvetica Neue", Helvetica, Arial, sans-serif;
        }
        .author-section {
            margin: 0 30px;
            margin-top: 30px;
            padding: 10px;
            background-color: #f9f9f9;
            border-left: 4px solid #2980b9;
        }
        .author-list {
            margin: 0;
            padding: 0;
            list-style-type: none;
        }
        .author-list li {
            font-weight: bold;
            padding: 5px 0;
        }
    </style>

    <script>
        function backToHome() {
            window.location.href = '/wordpress/';
        }

        function getRandomMatch() {
            fetch("https://raw.githubusercontent.com/openfootball/football.json/master/2020-21/en.1.json")
                .then(response => response.json())
                .then(data => {
                    const matches = data.matches; // wszystkie dostepne mecze z api

                    // Losowy mecz
                    const randomMatchIndex = Math.floor(Math.random() * matches.length);
                    const randomMatch = matches[randomMatchIndex];

                    const matchHTML = `
                        <h2 style="color:#4492d1;">LOSOWY MECZ FOOTBALL:</h2>
                        <h3 style="padding: 12px 0 4px 0;">${randomMatch.team1} vs ${randomMatch.team2}</h3>
                        <p style="font-size: 18px; padding-bottom: 12px;">Wynik: <strong>${randomMatch.score.ft[0]} - ${randomMatch.score.ft[1]}</strong></p>
                        <p style="font-size: 16px;">Data: <strong>${randomMatch.date}</strong></p>
                    `;
                    document.getElementById("footer-random").innerHTML = matchHTML;
                })
        }

        function data() {
            var data = new Date();
            var dzien = data.getDate();
            var dzienN = data.getDay();
            var miesiac = data.getMonth();
            var rok = data.getFullYear();

            var dni = new Array("niedziela", "poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota");
            var miesiace = new Array("stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "września", "października", "listopada", "grudnia");

            var pokazDate = dni[dzienN] + ', ' + dzien + " " + miesiace[miesiac] + ' ' + rok;
            document.getElementById("date").innerHTML = pokazDate;
        }
        function zegarek() {
            var data = new Date();
            var godzina = data.getHours();
            var minuta = data.getMinutes();
            var sekunda = data.getSeconds();

            if (minuta < 10) minuta = "0" + minuta;
            if (sekunda < 10) sekunda = "0" + sekunda;

            var pokazDate = godzina + ':' + minuta + ':' + sekunda;
            document.getElementById("time").innerHTML = pokazDate;

            setTimeout(zegarek, 1000);
        }

        function onloadFunc() {
            getRandomMatch();
            data();
            zegarek();
        }
    </script>
</head>
<body onload={onloadFunc()}>

    <div class="container">
        <header>
            <div class="logo-container" style="cursor: pointer;" onclick={backToHome()}>
                <img src="http://localhost/wordpress/wp-content/uploads/2024/10/logo.jpg" alt="Logo SkySport" class="logo">
                <span class="site-name">SkySport</span>
            </div>
            <div style="display: flex; align-items: center; gap: 20px; font-family: Arial, sans-serif; font-size: 16px;">
                <div id="date" style="font-weight: bold; padding: 10px 40px; background-color: #0f5e9d; color: white; border-radius: 8px; border-right: 5px solid #165079; border-bottom: 5px solid #165079;"></div>
                <div id="time" style="font-weight: bold; padding: 10px 30px; background-color: #0f5e9d; color: white; border-radius: 8px; border-right: 5px solid #165079; border-bottom: 5px solid #165079;"></div>
            </div>
            <nav class="navigation">
                <ul>
                    <li><a href="/wordpress/">Home</a></li>
                    <li><a href="/wordpress/about">About</a></li>
                    <li><a href="/wordpress/sports">Sports</a></li>
                    <li><a href="/wordpress/contact">Contact</a></li>
                </ul>
            </nav>
        </header>
        <main>