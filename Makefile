go:
	cp ~/Desktop/temp.csv .
	R --no-save <make_plot.R
	scp temp.png files.bensonk.net:files.bensonk.net/temp.png
