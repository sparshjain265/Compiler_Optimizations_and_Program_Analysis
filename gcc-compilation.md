Steps
1) Go to your home folder ($HOME)

2) clone the repository

3) copy the source file gcc-6.4.0-orginal.tar.gz  to your $HOME folder.

4) Extract the source file 

                  tar -xvf gcc-6.4.0-orginal.tar.gz

5) create directory of your wish (need not be gcc6.4) where gcc is installed. This under your home folder

                  mkdir gcc6.4

6) goto the gcc source folder

                  cd gcc-6.4.0

7) download the prerequesites for installing the gcc-6.4.0. The script in ./contrib folder of gcc-6.4.0 (current folder)

                  ./contrib/download_prerequisites

8) Extract all the downloaded source file archieves,       all th downloaded tar.gz file (tar -xvf)

9) Go to folder created in step 5

		  cd $HOME/gcc64

10) Configure gcc. Which also checks all the required dependencies are satisfied.

	          ../gcc-6.4.0/configure 

11) compile gcc souce (This took nearly four hours to compile. Keep terminal open, latop charged and focus on other works).


		time make

Note:- The files downloaded during step 7 on my laptop, and gcc source file is in the repo. But do the step 7, not copy from repo.

