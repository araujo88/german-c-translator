# german-translator
Simple command-line German to English translator using libcurl and Langenscheidt Wörterbuch as source.

# Dependencies

libcurl4-gnutls-dev

# Compile

`make`

# Usage

`./german-translator <word> <language>`

## Example 1

`./german-translator haus english` <br>
`house`

## Example 2

`./german-translator haus french` <br>
`maison`

## Example 3

`./german-translator haus portuguese` <br>
`casa`

## Example 4

`./german-translator haus russian` <br>
`дом`

# NOTE

Words containing umlaut (¨) needs to be transliterated as follows:

ä → ae <br>
ö → oe <br>
ü → ue <br>
ß → ss <br>

## Example

Translation for "übergeben":

`./german-translator uebergeben english` <br>
`to hand over to... ` <br>
`vomit... ` <br>
`to put sth around sb’s shoulders` <br>

