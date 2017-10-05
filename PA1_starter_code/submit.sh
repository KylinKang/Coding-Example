# Check files if they have been collected #
if [[ -f testBST.cpp ]] ; then
	echo "testBST.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: testBST.cpp. Exiting"
	exit
fi
if [[ -f BST.hpp ]] ; then
	echo "BST.hpp exists in directory"
else
	echo "MISSING REQUIRED FILE: BST.hpp. Exiting"
	exit
fi
if [[ -f BSTNode.hpp ]] ; then
	echo "BSTNode.hpp exists in directory"
else
	echo "MISSING REQUIRED FILE: BSTNode.hpp. Exiting"
	exit
fi
if [[ -f BSTIterator.hpp ]] ; then
	echo "BSTIterator.hpp exists in directory"
else
	echo "MISSING REQUIRED FILE: BSTIterator.hpp . Exiting"
	exit
fi
if [[ -f main.cpp ]] ; then
	echo "main.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: main.cpp . Exiting"
	exit
fi
if [[ -f Makefile ]] ; then
	echo "Makefile exists in directory"
else
	echo "Please keep the provided 'Makefile' in the same directory as that of the code files."
	exit
fi
if [[ -f actors.txt ]] ; then
	echo "actors.txt exists in directory"
else
	echo "Please keep the provided 'actors.txt' in the same directory as that of the code files."
	exit
fi
if [[ -f actors100.txt ]] ; then
	echo "actors100.txt exists in directory"
else
	echo "Please keep the provided 'actors100.txt' in the same directory as that of the code files."
	exit
fi
if [[ -f actors_sorted.txt ]] ; then
	echo "actors_sorted.txt exists in directory"
else
	echo "Please keep the provided 'actors_sorted.txt' in the same directory as that of the code files."
	exit
fi
# Copy makefile and extra exectuables into the current directory#
FILESDIR=`dirname "$0"`
ASNLIB="$FILESDIR/asnlib"

if [[ -d $ASNLIB ]] ; then
    cp $ASNLIB/makefile.pa1 ./
    cp $ASNLIB/fin_sub.cpp ./
    # Check compilation#
    make -f makefile.pa1 clean > temp.txt
    make -f makefile.pa1 main > temp.txt
    if [[ $? != 0 ]] ; then
        echo "Code doesn't compile. Exiting"
        rm -f makefile.pa1 temp.txt fin_sub.cpp
        exit
    fi
    echo "Code compiles successfully! (warnings may still exist)"
    # Run tests #
    echo "Running tests..."
    make -f makefile.pa1 clean > temp.txt
    make -f makefile.pa1 fin_sub > temp.txt
    if [[ $? != 0 ]] ; then
        echo "Code doesn't compile. Exiting"
        rm -f makefile.pa1 temp.txt fin_sub.cpp
        exit
    fi
    echo "Code compiles successfully! (warnings may still exist)"
    ./fin_sub > final_submission.txt
    if [[ $? != 0 ]] ; then
        echo "Test(s) failed. Exiting"
        rm -f makefile.pa1 temp.txt fin_sub.cpp
        exit
    fi
    valgrind --tool=memcheck --leak-check=full --error-exitcode=1 ./fin_sub > final_submission.txt
    if [[ $? != 0 ]] ; then
        echo "Memory leaks detected, hence deleteAll fails. Exiting"
        rm -f makefile.pa1 temp.txt fin_sub.cpp
        exit
    fi
    rm -f makefile.pa1 temp.txt fin_sub.cpp
    echo "Tests passed!"
    # test that all functions run without failing...
    echo "Running second wave of tests..."
    cp $ASNLIB/makefile.pa1 ./
    cp $ASNLIB/sub_test2.cpp ./
    # Check compilation#
    make -f makefile.pa1 clean > temp.txt
    make -f makefile.pa1 sub_test2 > temp.txt
    ./sub_test2
    if [[ $? != 0 ]] ; then
        echo "Test(s) failed. Exiting"
        rm -f makefile.pa1 temp.txt sub_test2.cpp
        exit
    fi
    rm -f makefile.pa1 temp.txt sub_test2.cpp sub_test2 sub_test2.o final_submission.txt
    echo "All submission checks passed. You're good to go."
else
    echo "$ASNLIB folder not found! Creating the zip but please keep the asnlib folder with th code files and run this script again to test your implementation for obvious errors."
fi

tar_file="PA1.tar.gz"
input_files="testBST.cpp BST.hpp BSTNode.hpp BSTIterator.hpp main.cpp"

tar -zcvf $tar_file $input_files
if [[ $? != 0 ]] ; then
    echo "Unable to create $tar_file! Exit Code: $?"
    exit
else
    echo "Successfully created $tar_file!"
fi
