EXEC_DIR = Execs
ASM_DIR = Assembly
FILES = $(ASM_DIR)/BoxMaker.S $(EXEC_DIR)/BoxMaker $(ASM_DIR)/BoxMakerdemangled.S \
		$(EXEC_DIR)/TricycleClassOOP $(ASM_DIR)/TricycleClassOOPdemangled.S \
		$(EXEC_DIR)/NewTricycle $(ASM_DIR)/NewTricycledemangled.S \
		$(EXEC_DIR)/Tricycle $(ASM_DIR)/Tricycledemangled.S \
		$(EXEC_DIR)/Rectangle $(ASM_DIR)/Rectangledemangled.S \
		$(EXEC_DIR)/RectangleOverloading $(ASM_DIR)/RectangleOverloadingdemangled.S \
		$(EXEC_DIR)/BinarySearchTraditional $(ASM_DIR)/BinarySearchTraditionaldemangled.S \
		$(EXEC_DIR)/BinarySearchFindUpperBound $(ASM_DIR)/BinarySearchFindUpperBounddemangled.S \
		$(EXEC_DIR)/BinarySearchFindLowerBound $(ASM_DIR)/BinarySearchFindLowerBounddemangled.S \
		$(EXEC_DIR)/BinarySearchwithBuiltInToolsUpperBound $(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBounddemangled.S \
		$(EXEC_DIR)/69.Sqrtx $(ASM_DIR)/69.Sqrtxdemangled.S \
		$(EXEC_DIR)/69.SqrtxRecursive $(ASM_DIR)/69.SqrtxRecursivedemangled.S \
		$(EXEC_DIR)/633.SumofSquareNumbers $(ASM_DIR)/633.SumofSquareNumbersdemangled.S \
		$(EXEC_DIR)/374.GuessNumberHigherOrLower $(ASM_DIR)/374.GuessNumberHigherOrLowerdemangled.S \
		$(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S \
		$(EXEC_DIR)/94.BinaryTreeInOrderTraversal $(ASM_DIR)/94.BinaryTreeInOrderTraversal.S \
		$(EXEC_DIR)/94.BinaryTreeInOrderTraversalModernCpp $(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCpp.S \
		$(EXEC_DIR)/33.SearchinRotatedArray $(ASM_DIR)/33.SearchinRotatedArray.S \
		$(EXEC_DIR)/AbdBari.281.Height&CountofBinaryTree $(ASM_DIR)/AbdBari.281.Height&CountofBinaryTree.S \
		$(EXEC_DIR)/438.FindAllAnagramsInAString $(ASM_DIR)/438.FindAllAnagramsInAString.S \

# The .DELETE_ON_ERROR: target tells Make to delete the target files if the recipe fails ensuring that we don't end up with partial or corrupted files
.DELETE_ON_ERROR:

all: $(FILES)


#The | symbol denotes an "order-only" dependency, meaning the directory needs to exist before the target is built,
# but changes to the directory itself won't trigger a build.

# -fverbose-asm adds inline comments to the assembly showing the original C++ lines and sometimes demangled names.
# You can also demangle the whole assembly with command ' c++filt < BoxMaker.s > demangled.s

#The $@ in the compile commands refer to the target file name


#Assembly PART. every x
#----------------------------

$(ASM_DIR)/BoxMaker.S: BoxMaker.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/TricycleClassOOP.S: TricycleClassOOP.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/NewTricycle.S: NewTricycle.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/Tricycle.S: Tricycle.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/Rectangle.S: Rectangle.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/RectangleOverloading.S: RectangleOverloading.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/BinarySearchTraditional.S: LeetcodeGrind/BinarySearch/BinarySearchTraditional.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/BinarySearchFindUpperBound.S: LeetcodeGrind/BinarySearch/BinarySearchFindUpperBound.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/BinarySearchFindLowerBound.S: LeetcodeGrind/BinarySearch/BinarySearchFindLowerBound.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBound.S: LeetcodeGrind/BinarySearch/BinarySearchwithBuiltInToolsUpperBound.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/69.Sqrtx.S: LeetcodeGrind/BinarySearch/69.Sqrtx.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/633.SumofSquareNumbers.S: LeetcodeGrind/BinarySearch/633.SumofSquareNumbers.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/69.SqrtxRecursive.S: LeetcodeGrind/BinarySearch/69.SqrtxRecursive.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/374.GuessNumberHigherOrLower.S: LeetcodeGrind/BinarySearch/374.GuessNumberHigherOrLower.cpp | $(ASM_DIR)
	g++ -std=c++11  -S \
	-O0	\
	$< \
	-o $@


$(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S: LeetcodeGrind/BinarySearch/BinarySearchVariationsTheoryBoundaryVsExactMatch.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	$< \
	-o $@

$(ASM_DIR)/94.BinaryTreeInOrderTraversal.S: LeetcodeGrind/Trees/94.BinaryTreeInOrderTraversal.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	$< \
	-o $@
	
$(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCpp.S: LeetcodeGrind/Trees/94.BinaryTreeInOrderTraversalModernCpp.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	$< \
	-o $@
	
$(ASM_DIR)/33.SearchinRotatedArray.S: LeetcodeGrind/BinarySearch/33.SearchinRotatedArray.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	$< \
	-o $@
	
# Quote $@ and $< in all recipes that touch the & file. Make targets can have &, but the shell will split on it. So wrap them.
# The quotes around "$@" and "$<" make the shell treat the whole filename as one argument, so & doesn't fork it.
$(ASM_DIR)/AbdBari.281.Height&CountofBinaryTree.S: LeetcodeGrind/Trees/AbdBari.281.Height&CountofBinaryTree.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	"$<" \
	-o "$@"


$(ASM_DIR)/438.FindAllAnagramsInAString.S: LeetcodeGrind/SlidingWindow/438.FindAllAnagramsInAString.cpp | $(ASM_DIR)
	g++ -std=c++14 -S \
	-O0	\
	"$<" \
	-o "$@"









#Demangled PART. every x
#------------------------------

# $< means the first prerequisite of the current rule (it means “the first thing after the colon in the target line”).
# Target: output.o Prerequisites: source.cpp (first), header.h (second). $< → source.cpp. $@ → output.o
$(ASM_DIR)/BoxMakerdemangled.S: $(ASM_DIR)/BoxMaker.S
	c++filt < $< > $@

$(ASM_DIR)/TricycleClassOOPdemangled.S: $(ASM_DIR)/TricycleClassOOP.S
	c++filt < $< > $@

$(ASM_DIR)/NewTricycledemangled.S: $(ASM_DIR)/NewTricycle.S
	c++filt < $< > $@

$(ASM_DIR)/Tricycledemangled.S: $(ASM_DIR)/Tricycle.S
	c++filt < $< > $@

$(ASM_DIR)/Rectangledemangled.S: $(ASM_DIR)/Rectangle.S
	c++filt < $< > $@

$(ASM_DIR)/RectangleOverloadingdemangled.S: $(ASM_DIR)/RectangleOverloading.S
	c++filt < $< > $@

$(ASM_DIR)/BinarySearchTraditionaldemangled.S: $(ASM_DIR)/BinarySearchTraditional.S
	c++filt < $< > $@

$(ASM_DIR)/BinarySearchFindUpperBounddemangled.S: $(ASM_DIR)/BinarySearchFindUpperBound.S
	c++filt < $< > $@

$(ASM_DIR)/BinarySearchFindLowerBounddemangled.S: $(ASM_DIR)/BinarySearchFindLowerBound.S
	c++filt < $< > $@

$(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBounddemangled.S: $(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBound.S
	c++filt < $< > $@

$(ASM_DIR)/69.Sqrtxdemangled.S: $(ASM_DIR)/69.Sqrtx.S
	c++filt < $< > $@

$(ASM_DIR)/69.SqrtxRecursivedemangled.S: $(ASM_DIR)/69.SqrtxRecursive.S
	c++filt < $< > $@

$(ASM_DIR)/633.SumofSquareNumbersdemangled.S: $(ASM_DIR)/633.SumofSquareNumbers.S
	c++filt < $< > $@

$(ASM_DIR)/374.GuessNumberHigherOrLowerdemangled.S: $(ASM_DIR)/374.GuessNumberHigherOrLower.S
	c++filt < $< > $@

$(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatchdemangled.S: $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S
	c++filt < $< > $@

$(ASM_DIR)/94.BinaryTreeInOrderTraversaldemangled.S: $(ASM_DIR)/94.BinaryTreeInOrderTraversal.S
	c++filt < $< > $@

$(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCppdemangled.S: $(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCpp.S
	c++filt < $< > $@

$(ASM_DIR)/33.SearchinRotatedArraydemangled.S: $(ASM_DIR)/33.SearchinRotatedArray.S
	c++filt < $< > $@

$(ASM_DIR)/AbdBari.281.Height&CountofBinaryTreedemangled.S: $(ASM_DIR)/AbdBari.281.Height&CountofBinaryTree.S
	c++filt < "$<"" > "$@"

$(ASM_DIR)/438.FindAllAnagramsInAStringdemangled.S: $(ASM_DIR)/438.FindAllAnagramsInAString.S
	c++filt < "$<"" > "$@"


# Executable PART. every x 
#----------------------------

$(EXEC_DIR)/BoxMaker: BoxMaker.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/TricycleClassOOP: TricycleClassOOP.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/NewTricycle: NewTricycle.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/Tricycle: Tricycle.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/Rectangle: Rectangle.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/RectangleOverloading: RectangleOverloading.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/BinarySearchTraditional: LeetcodeGrind/BinarySearch/BinarySearchTraditional.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@

$(EXEC_DIR)/BinarySearchFindUpperBound: LeetcodeGrind/BinarySearch/BinarySearchFindUpperBound.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/BinarySearchFindLowerBound: LeetcodeGrind/BinarySearch/BinarySearchFindLowerBound.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/BinarySearchwithBuiltInToolsUpperBound: LeetcodeGrind/BinarySearch/BinarySearchwithBuiltInToolsUpperBound.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/69.Sqrtx: LeetcodeGrind/BinarySearch/69.Sqrtx.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/69.SqrtxRecursive: LeetcodeGrind/BinarySearch/69.SqrtxRecursive.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/633.SumofSquareNumbers: LeetcodeGrind/BinarySearch/633.SumofSquareNumbers.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/374.GuessNumberHigherOrLower: LeetcodeGrind/BinarySearch/374.GuessNumberHigherOrLower.cpp | $(EXEC_DIR)
	g++ -std=c++11  -g $< -o $@


$(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch: LeetcodeGrind/BinarySearch/BinarySearchVariationsTheoryBoundaryVsExactMatch.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g $< -o $@


$(EXEC_DIR)/94.BinaryTreeInOrderTraversal: LeetcodeGrind/Trees/94.BinaryTreeInOrderTraversal.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g $< -o $@

$(EXEC_DIR)/94.BinaryTreeInOrderTraversalModernCpp: LeetcodeGrind/Trees/94.BinaryTreeInOrderTraversalModernCpp.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g $< -o $@

$(EXEC_DIR)/33.SearchinRotatedArray: LeetcodeGrind/BinarySearch/33.SearchinRotatedArray.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g $< -o $@


$(EXEC_DIR)/AbdBari.281.Height&CountofBinaryTree: LeetcodeGrind/Trees/AbdBari.281.Height&CountofBinaryTree.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g "$<" -o "$@"


$(EXEC_DIR)/438.FindAllAnagramsInAString: LeetcodeGrind/SlidingWindow/438.FindAllAnagramsInAString.cpp | $(EXEC_DIR)
	g++ -std=c++14 -g "$<" -o "$@"


# Directory PART, created ONCE, no need to keep recreating.
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Create the two directories i.e. Assembly and Exec directories
$(ASM_DIR) $(EXEC_DIR):
	mkdir -p $@

# Cleaning PART
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

FILES_TO_CLEAN = $(ASM_DIR)/BoxMaker.S $(EXEC_DIR)/BoxMaker $(ASM_DIR)/BoxMakerdemangled.S \
					$(ASM_DIR)/TricycleClassOOP.S $(EXEC_DIR)/TricycleClassOOP $(ASM_DIR)/TricycleClassOOPdemangled.S \
					$(ASM_DIR)/NewTricycle.S $(EXEC_DIR)/NewTricycle $(ASM_DIR)/NewTricycledemangled.S \
					$(ASM_DIR)/Tricycle.S $(EXEC_DIR)/Tricycle $(ASM_DIR)/Tricycledemangled.S \
					$(ASM_DIR)/Rectangle.S $(EXEC_DIR)/Rectangle $(ASM_DIR)/Rectangledemangled.S \
					$(ASM_DIR)/RectangleOverloading.S $(EXEC_DIR)/RectangleOverloading $(ASM_DIR)/RectangleOverloadingdemangled.S \
					$(ASM_DIR)/BinarySearchTraditional.S $(EXEC_DIR)/BinarySearchTraditional $(ASM_DIR)/BinarySearchTraditionaldemangled.S \
					$(ASM_DIR)/BinarySearchFindUpperBound.S $(EXEC_DIR)/BinarySearchFindUpperBound $(ASM_DIR)/BinarySearchFindUpperBounddemangled.S \
					$(ASM_DIR)/BinarySearchFindLowerBound.S $(EXEC_DIR)/BinarySearchFindLowerBound $(ASM_DIR)/BinarySearchFindLowerBounddemangled.S \
					$(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBound.S $(EXEC_DIR)/BinarySearchwithBuiltInToolsUpperBound $(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBounddemangled.S \
					$(ASM_DIR)/69.Sqrtx.S $(EXEC_DIR)/69.Sqrtx $(ASM_DIR)/69.Sqrtxdemangled.S \
					$(ASM_DIR)/69.SqrtxRecursive.S $(EXEC_DIR)/69.SqrtxRecursive $(ASM_DIR)/69.SqrtxRecursivedemangled.S \
					$(ASM_DIR)/633.SumofSquareNumbers.S $(EXEC_DIR)/633.SumofSquareNumbers $(ASM_DIR)/633.SumofSquareNumbersdemangled.S \
					$(ASM_DIR)/374.GuessNumberHigherOrLower.S $(EXEC_DIR)/374.GuessNumberHigherOrLower $(ASM_DIR)/374.GuessNumberHigherOrLowerdemangled.S \
					$(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S $(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatchdemangled.S \
					$(ASM_DIR)/94.BinaryTreeInOrderTraversal.S $(EXEC_DIR)/94.BinaryTreeInOrderTraversal $(ASM_DIR)/94.BinaryTreeInOrderTraversaldemangled.S \
					$(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCpp.S $(EXEC_DIR)/94.BinaryTreeInOrderTraversalModernCpp $(ASM_DIR)/94.BinaryTreeInOrderTraversalModernCppdemangled.S \
					$(ASM_DIR)/33.SearchinRotatedArray.S $(EXEC_DIR)/33.SearchinRotatedArray $(ASM_DIR)/33.SearchinRotatedArraydemangled.S \
					$(ASM_DIR)/AbdBari.281.Height&CountofBinaryTree.S $(EXEC_DIR)/AbdBari.281.Height&CountofBinaryTree $(ASM_DIR)/AbdBari.281.Height&CountofBinaryTreedemangled.S \
					$(ASM_DIR)/438.FindAllAnagramsInAString.S $(EXEC_DIR)/438.FindAllAnagramsInAString $(ASM_DIR)/438.FindAllAnagramsInAStringdemangled.S \

# Also, consider adding a .PHONY directive for the clean target to prevent potential issues if a file named clean exists in your directory
.PHONY: clean
clean:
# 	rm -rf $(FILES_TO_CLEAN) $(ASM_DIR) $(EXEC_DIR)
	rm -rf $(foreach f,$(FILES_TO_CLEAN),"$(f)") $(ASM_DIR) $(EXEC_DIR)
# The $(foreach f,$(FILES_TO_CLEAN),"$(f)") wraps every single file in double quotes before passing to rm. Now the shell sees "Assembly/AbdBari.281.Height&CountofBinaryTree.S" as one argument.
