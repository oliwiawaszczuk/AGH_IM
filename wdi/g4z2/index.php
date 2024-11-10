<?php get_header(); ?>

    <style>
        body {
            background-color: rgb(178, 203, 219);
        }
        .parent {
            background-color: rgb(212, 224, 230);
            display: grid;
            grid-template-columns: repeat(5, 1fr);
            grid-template-rows: repeat(5, 1fr);
            gap: 0px;
            width: 100%;
            height: 100vh;
        }

        .div1 { grid-area: 1 / 1 / 3 / 3; }
        .div2 { grid-area: 1 / 3 / 3 / 6; }
        .div3 { grid-area: 3 / 1 / 6 / 4; }
        .div4 { grid-area: 3 / 4 / 6 / 6; }

        .parent div {
            position: relative;
            overflow: hidden;
            cursor: pointer;
        }

        .div1, .div2, .div3, .div4 {
            border: 4px solid rgb(178, 203, 219);
        }

        .parent div::before {
            content: "";
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-size: cover;
            background-position: center;
            transition: transform 0.3s ease;
        }

        .div1::before { background-image: url('https://pbs.twimg.com/media/EgIu5NwWAAIymV_?format=jpg&name=medium'); }
        .div2::before { background-image: url('https://v.wpimg.pl/OTUwMDQuYDU0FTt3fg5tIHdNby04V2N2IFV3Zn5EfWRlD3tzZFo8MngWKSk4GyYnIQUsJzsUYSMlFCkqfwUjeyYDIjYwEipmehEoJSUAPTExKCI2OBImOjQbYnJnFHZmNE8rdjRMf2FtKH18YEx6ZGVDYy4hEm0p'); }
        .div3::before { background-image: url('https://zkrainynba.com/wp-content/uploads/2023/10/GettyImages-1728621765-1400x933.jpg'); }
        .div4::before { background-image: url('https://sweet-tv-static.sweet.tv/web/vue/landing/olympiad/images/kindsOfSport/swimming2.webp'); }

        .parent div:hover::before {
            transform: scale(0.9);
        }

        .text-overlay {
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            font-family: "Roboto Condensed", Arial, sans-serif;
            color: #ffffff;
            font-size: 34px;
            font-weight: 800;
            text-align: center;
            padding: 10px 20px;
            border-radius: 5px;
            -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: #1a3a5f;
            text-shadow: 2px 2px 8px rgba(0, 0, 0, 0.6);
        }
    </style>

    <div class="parent">
        <div class="div1" onclick="location.href='/wordpress/article1'">
            <div class="text-overlay">Robert Lewandowski - Mistrz Strzałów</div>
        </div>
        <div class="div2" onclick="location.href='/wordpress/article2'">
            <div class="text-overlay">Iga Świątek - Gwiazda Tenisa</div>
        </div>
        <div class="div3" onclick="location.href='/wordpress/article3'">
            <div class="text-overlay">Historia i Rozwój Koszykówki</div>
        </div>
        <div class="div4" onclick="location.href='/wordpress/article4'">
            <div class="text-overlay">Historia Pływania – Od Starożytności do Sportu Olimpijskiego</div>
        </div>
    </div>

<?php get_footer(); ?>

