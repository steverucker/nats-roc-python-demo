#
# Makefile to reproduce ROC algorithm accuracy on the LFW and MEDS datasets.
#

# By default make both the text score matrices and the pdf accuracy plots
all: lfw.tsv lfw.pdf meds.tsv meds.pdf

# Download the LFW dataset
lfw:
	wget http://vis-www.cs.umass.edu/lfw/lfw.tgz
	tar -xf lfw.tgz
	rm lfw.tgz

# List the files in LFW
lfw.txt: lfw
	find lfw -type f > lfw.txt

# Construct a template for each file (using the ROCFR algorithm)
lfw.t: lfw.txt
	roc-represent -e -f 1 -l lfw.txt lfw.t

# Compare templates into a text self-similarity matrix
lfw.tsv: lfw.t
	roc-compare lfw.t lfw.t lfw.tsv

# Compare templates into a binary self-similarity matrix
lfw.mtx: lfw.t
	roc-compare -b lfw.t lfw.t lfw.mtx

# Construct the ground truth from the file names
lfw.mask: lfw.txt
	br -makeMask lfw.txt lfw.txt lfw.mask

# Evaluate the similarity matrix against the ground truth
lfw.csv: lfw.mtx lfw.mask
	br -eval lfw.mtx lfw.mask lfw.csv

# Plot the results!
lfw.pdf: lfw.csv
	br -plot lfw.csv lfw.pdf

# Download the MEDS dataset (and rearrange the files)
meds:
	wget http://nigos.nist.gov:8080/nist/sd/32/NIST_SD32_MEDS-II_face.zip
	unzip NIST_SD32_MEDS-II_face.zip
	rm NIST_SD32_MEDS-II_face.zip
	mv data meds
	mv meds/*/* meds/
	rm -r meds/a*
	for i in `seq -w 518` ;               \
	do                                    \
		mkdir meds/$${i} ;            \
		mv meds/S$${i}* meds/$${i}/ ; \
	done

# List the files in MEDS
meds.txt: meds
	find meds -type f > meds.txt

# Construct a template for each file (using the ROCID algorithm)
meds.t: meds.txt
	roc-represent -e -f 1 -i -l meds.txt meds.t

# Compare templates into a text self-similarity matrix
meds.tsv: meds.t
	roc-compare meds.t meds.t meds.tsv

# Compare templates into a binary self-similarity matrix
meds.mtx: meds.t
	roc-compare -b meds.t meds.t meds.mtx

# Construct the ground truth from the file names
meds.mask: meds.txt
	br -makeMask meds.txt meds.txt meds.mask

# Evaluate the similarity matrix against the ground truth
meds.csv: meds.mtx meds.mask
	br -eval meds.mtx meds.mask meds.csv

# Plot the results
meds.pdf: meds.csv
	br -plot meds.csv meds.pdf

# Delete all the files that were created
clean:
	rm -rf lfw* meds*
