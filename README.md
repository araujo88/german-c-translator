# german-translator
Simple command-line German translator using libcurl and Langenscheidt Wörterbuch as source.

# Dependencies

libcurl4-gnutls-dev

# Compile

`make`

# Usage

`./german-translator <word> <input-language> <output-language>`

## Example 1

`./german-translator haus german english` <br>
`house`

## Example 2

`./german-translator haus german french` <br>
`maison`

## Example 3

`./german-translator haus german portuguese` <br>
`casa`

## Example 4

`./german-translator haus german russian` <br>
`дом`

## Example 5

`./german-translator DEVELOPMENT english german` <br>
`Entwicklung`

## Example 6

`./german-translator computador portuguese german` <br>
`Computer`

# NOTE

Words containing umlaut (¨) needs to be transliterated as follows:

ä → ae <br>
ö → oe <br>
ü → ue <br>
ß → ss <br>

## Example

Translation for "übergeben":

`./german-translator uebergeben german english` <br>
`to hand over to... ` <br>
`vomit... ` <br>
`to put sth around sb’s shoulders` <br>

