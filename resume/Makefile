SRC = $(wildcard *.md)
PDFS = $(SRC:.md=.pdf)
DOCXS = $(SRC:.md=.docx)
HTML=$(SRC:.md=.html)

PANDOCARGS = --latex-engine=xelatex

all: $(PDFS) $(DOCXS) $(HTML)

pdf: $(PDFS)
docx: $(DOCXS)
html: $(HTML)

%.pdf: %.md
	pandoc $< $(PANDOCARGS) -H header.tex -V papersize:'a4paper' -f markdown -t latex -o $@

%.docx: %.md
	pandoc $< -o $@

%.html: %.md
	pandoc $< -t html -c resume.css -o $@

clean:
	rm *.pdf *.html *.docx