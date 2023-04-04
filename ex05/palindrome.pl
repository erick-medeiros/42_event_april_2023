#!/bin/perl

#show errors
use strict;
use warnings;
use diagnostics;

#string format
use utf8;
use feature 'say';

print "Enter a string: ";
my $input = <STDIN>;

if (!defined($input))
{
    say "";
    exit ;
}

#regex
$input =~ tr/ //ds;
$input = lc $input;
$input =~ s/[áàâãä]/a/gi;
$input =~ s/[éèêë]/e/gi;
$input =~ s/[íìîï]/i/gi;
$input =~ s/[óòôõö]/o/gi;
$input =~ s/[úùûü]/u/gi;
$input =~ s/[^a-zA-Z0-9]//g;

my $compare = reverse $input;

if (($compare eq $input) && (length $input >= 1))
{
    say "The string is a palindrome!";
}
else
{
    say "The string is not a palindrome.";
}