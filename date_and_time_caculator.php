<!DOCTYPE html>
<html>
<head>
    <title>Time Difference Calculator</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
    <style>
        .result {
            margin-top: 20px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Time Difference Calculator</h1>
        <form action="" method="post">
            <div class="mb-3">
                <label for="start_date" class="form-label">Starting Date (YYYY-MM-DD):</label>
                <input type="text" class="form-control" id="start_date" name="start_date" required>
            </div>
            <div class="mb-3">
                <label for="start_time" class="form-label">Starting Time (HH:MM):</label>
                <input type="text" class="form-control" id="start_time" name="start_time" required>
            </div>
            <div class="mb-3">
                <label for="end_date" class="form-label">End Date (YYYY-MM-DD):</label>
                <input type="text" class="form-control" id="end_date" name="end_date" required>
            </div>
            <div class="mb-3">
                <label for="end_time" class="form-label">End Time (HH:MM):</label>
                <input type="text" class="form-control" id="end_time" name="end_time" required>
            </div>
            <div class="mb-3">
                <button type="submit" class="btn btn-primary">Calculate</button>
            </div>
        </form>
        <?php
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $start_date = $_POST['start_date'];
            $start_time = $_POST['start_time'];
            $end_date = $_POST['end_date'];
            $end_time = $_POST['end_time'];

            $start_datetime = DateTime::createFromFormat('Y-m-d H:i', $start_date . ' ' . $start_time);
            $end_datetime = DateTime::createFromFormat('Y-m-d H:i', $end_date . ' ' . $end_time);
            $time_difference = $end_datetime->diff($start_datetime);

            $years = $time_difference->y;
            $months = $time_difference->m;
            $weeks = floor($time_difference->d / 7);
            $days = $time_difference->d;
            $hours = $time_difference->h;
            $minutes = $time_difference->i;

            echo '<div class="result">';
            echo 'Time Difference:<br>';
            echo 'Years: ' . $years . '<br>';
            echo 'Months: ' . $months . '<br>';
            echo 'Weeks: ' . $weeks . '<br>';
            echo 'Days: ' . $days . '<br>';
            echo 'Hours: ' . $hours . '<br>';
            echo 'Minutes: ' . $minutes . '<br>';
            echo '</div>';
        }
        ?>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>

