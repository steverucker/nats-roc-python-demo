Licensing
---------
To generate a valid license file run:

    $ ./bin/zlmhostid

This command will generate a file called `zlmhostid.txt`.
Email this file to `support@rankone.io`.
We will respond with a valid `ROC.lic` file to copy to the ROC SDK root directory, overwriting the placeholder license file of the same name.

Documentation
-------------
Point your browser to [here](html/index.html).

Support
-------
Get in touch with us over email at `support@rankone.io`.

Video Decoding
--------------
An additional installation step is required _only_ for users in need of video decoding using the ROC API.

### Ubuntu 14.04

    $ sudo apt-get install libavcodec-dev libavformat-dev libavdevice-dev libavfilter-dev libswscale-dev

### Windows Server 2012

No additional installation step.

### OS X 10.10

    $ brew install ffmpeg

Evaluation
----------
The `Makefile` in the root of the SDK is provided as a turn-key solution for evaluating ROC algorithms on the [LFW](http://vis-www.cs.umass.edu/lfw/) and [MEDS](http://www.nist.gov/itl/iad/ig/sd32.cfm) datasets.
See comments in the Makefile for details.

### Generate plain-text score matrices

    $ export PATH=$PATH:./bin
    $ make lfw.tsv meds.tsv

Note that `lfw.tsv` and `meds.tsv` are tab-separated self-similarity matrices.
The order of the rows and columns are specified by `lfw.txt` and `meds.txt` respectively.

### Plot accuracy

    $ export PATH=$PATH:./bin
    $ make lfw.pdf meds.pdf

Note that this requires the [OpenBR](http://www.openbiometrics.org) command line application `br` ([this commit](https://github.com/biometrics/openbr/commit/35001d4c457fc6dd5be560a1701c8ed93695931b) or newer) and [R](https://www.r-project.org/) with the packages `install.packages(c("ggplot2", "gplots", "reshape", "scales", "jpg", "png"))`.

Acknowledgements
----------------
ROC makes use of the following software packages:

| Name   | Version | License                                                            | Source                         |
|--------|---------|--------------------------------------------------------------------|--------------------------------|
| OpenBR | -       | [Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0)           | http://www.openbiometrics.org  |
| Qt     | 5.5     | [LGPL 3.0](http://www.gnu.org/licenses/lgpl-3.0.html)              | http://www.qt.io               |
| OpenCV | 2.4.11  | [BSD 3-clause](http://opensource.org/licenses/BSD-3-Clause)        | http://www.opencv.org          |
| Eigen  | 3.2.6   | [MPL 2.0](https://www.mozilla.org/en-US/MPL/2.0/)                  | http://www.eigen.tuxfamily.org |
| FFMPEG | -       | [LGPL 2.1](http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html) | http://www.ffmpeg.org          |
