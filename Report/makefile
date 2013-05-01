FILE = report

FIGURES = # .eps

TEX = pdflatex

full:
	pdflatex $(FILE)
	bibtex $(FILE)
	pdflatex $(FILE)
	pdflatex $(FILE)

single:
	pdflatex $(FILE)

convert:
	epspdf $(FIGURES)


