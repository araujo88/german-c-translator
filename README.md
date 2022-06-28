# german-translator
Simple command-line German to English translator using libcurl and Langenscheidt Wörterbuch as source.

# Dependencies

libcurl4-gnutls-dev

# Compile

`make`

# Usage

`./german-translator <word> <language>`

## Example

`./german-translator haus english`

### Output

`house`

# NOTE

Words containing umlaut (¨) needs to be transliterated as follows:

ä → ae <br>
ö → oe <br>
ü → ue <br>
ß → ss <br>

## Example

Translation for "übergeben":

`./german-translator uebergeben english`

### Output

`to hand over to... ` <br>
`vomit... ` <br>
`to put sth around sb’s shoulders` <br>

