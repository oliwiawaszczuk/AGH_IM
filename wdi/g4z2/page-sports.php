<?php get_header(); ?>
    <style>
        .sports table {
            width: 70%;
            margin: 20px auto;
            font-family: Arial, sans-serif;
        }

        .sports th, .sports td {
            padding: 12px;
            border: 1px solid #ddd;
            text-align: left;
        }

        .sports th {
            background-color: #004b87;
            color: white;
            font-weight: bold;
        }

        .sports tr:nth-child(even) {
            background-color: #f9f9f9;
        }

        .sports tr:hover {
            background-color: #eaf4fc;
        }
    </style>
    <div class="sports">
        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "sports";

        $conn = new mysqli($servername, $username, $password, $dbname);
        if ($conn->connect_error) {
            die("Połączenie nie powiodło się: " . $conn->connect_error);
        }

        // Pobrania danych
        $sql = "SELECT name, founded FROM sport";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            echo '<table>';
            echo '<thead><tr><th>Sport</th><th>Założony</th></tr></thead>';
            echo '<tbody>';
            while ($row = $result->fetch_assoc()) {
                echo '<tr>';
                echo '<td>' . $row["name"] . '</td>';
                echo '<td>' . $row["founded"] . '</td>';
                echo '</tr>';
            }
            echo '</tbody></table>';
        }
        $conn->close();
        ?>
    </div>

<?php get_footer(); ?>