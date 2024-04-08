<?php
	$arraySize = $_POST['size'];
	echo '<style>';
		echo 'table {border: 1px solid black;}';
		echo 'th, td {border: 1px solid black;}';
	echo '</style>';
	echo '<table><tr>';
	echo '<td>     </td>';
	for ($k = 1; $k <= $arraySize; $k++) {
		echo '<td>' . $k . '</td>';
	}
	echo '</tr>';
	for ($i = 1; $i <= $arraySize; $i++) {
		echo '<tr><td>' . $i . '</td>';
		for ($j = 1; $j <= $arraySize; $j++) {
			echo '<td>' . ($i * $j) . '</td>';
		}
		echo '</tr>';
	}
	echo '</table>';
?>