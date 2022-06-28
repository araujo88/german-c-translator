# german-english-c-translator
Simple command-line German to English translator using libcurl and Langenscheidt Wörterbuch as source. It prints out the first translation found on the website.

# Dependencies

libcurl4-gnutls-dev

# Compile

`make`

# Usage

`./german-english <word>`

## Example

`./german-english allerdings`

### Output

`though`

# NOTE

Words containing umlaut (¨) needs to be transliterated as follows:

ä → ae
ö → oe
ü → ue
ß → ss

## Example

Translation for "übergeben":

`./german-english uebergeben`

### Output

`to hand over to...`

