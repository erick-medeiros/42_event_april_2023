<?php

$list = array("rock", "paper", "scissors");

$stdin = fopen("php://stdin", "r");

while (1) {
	echo "Choose rock, paper, or scissors: ";
	$line = rtrim(fgets($stdin));
	if (feof($stdin))
		return;
	if (!in_array($line, $list))
		echo "Invalid option: $line\n";
	else
		break;
}

fclose($stdin);

$u = array_search($line, $list); // user
$c = rand(0, 2); // computer

if ($u == $c)
	echo "Tied game.";
else if (($c > $u && !($c == 2 && $u == 0)) || ($c == 0 && $u == 2))
	echo "Sorry, you lost.";
else
	echo "Congratulations! You won!";

echo " The computer chose $list[$c].\n"

?>
