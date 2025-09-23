EXEC_DIR = Execs
ASM_DIR = Assembly

# The .DELETE_ON_ERROR: target tells Make to delete the target files if the recipe fails ensuring that we don't end up with partial or corrupted files
.DELETE_ON_ERROR:

all: $(ASM_DIR)/BoxMaker.S $(EXEC_DIR)/BoxMaker $(ASM_DIR)/BoxMakerdemangled.S \
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
	$(EXEC_DIR)/374.GuessNumberHigherOrLower $(ASM_DIR)/374.GuessNumberHigherOrLowerdemangled.S \
	$(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S \


#The | symbol denotes an "order-only" dependency, meaning the directory needs to exist before the target is built,
# but changes to the directory itself won't trigger a build.

# -fverbose-asm adds inline comments to the assembly showing the original C++ lines and sometimes demangled names.
# You can also demangle the whole assembly with command ' c++filt < BoxMaker.s > demangled.s

#The $@ in the compile commands refer to the target file name


#Assembly PART
$(ASM_DIR)/BoxMaker.S: BoxMaker.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/TricycleClassOOP.S: TricycleClassOOP.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/NewTricycle.S: NewTricycle.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/Tricycle.S: Tricycle.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/Rectangle.S: Rectangle.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/RectangleOverloading.S: RectangleOverloading.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/BinarySearchTraditional.S: LeetcodeGrind/BinarySearch/BinarySearchTraditional.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/BinarySearchFindUpperBound.S: LeetcodeGrind/BinarySearch/BinarySearchFindUpperBound.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


$(ASM_DIR)/BinarySearchFindLowerBound.S: LeetcodeGrind/BinarySearch/BinarySearchFindLowerBound.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


$(ASM_DIR)/BinarySearchwithBuiltInToolsUpperBound.S: LeetcodeGrind/BinarySearch/BinarySearchwithBuiltInToolsUpperBound.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


$(ASM_DIR)/69.Sqrtx.S: LeetcodeGrind/BinarySearch/69.Sqrtx.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


$(ASM_DIR)/69.SqrtxRecursive.S: LeetcodeGrind/BinarySearch/69.SqrtxRecursive.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@
	-o $@


$(ASM_DIR)/374.GuessNumberHigherOrLower.S: LeetcodeGrind/BinarySearch/374.GuessNumberHigherOrLower.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


$(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S: LeetcodeGrind/BinarySearch/BinarySearchVariationsTheoryBoundaryVsExactMatch.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

#Demangled PART

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

$(ASM_DIR)/374.GuessNumberHigherOrLowerdemangled.S: $(ASM_DIR)/374.GuessNumberHigherOrLower.S
	c++filt < $< > $@

BinarySearchVariationsTheoryBoundaryVsExactMatchdemangled.S: $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S
	c++filt < $< > $@


# Executable PART
#----------------------------

$(EXEC_DIR)/BoxMaker: BoxMaker.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/TricycleClassOOP: TricycleClassOOP.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/NewTricycle: NewTricycle.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/Tricycle: Tricycle.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/Rectangle: Rectangle.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/RectangleOverloading: RectangleOverloading.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/BinarySearchTraditional: LeetcodeGrind/BinarySearch/BinarySearchTraditional.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/BinarySearchFindUpperBound: LeetcodeGrind/BinarySearch/BinarySearchFindUpperBound.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/BinarySearchFindLowerBound: LeetcodeGrind/BinarySearch/BinarySearchFindLowerBound.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/BinarySearchwithBuiltInToolsUpperBound: LeetcodeGrind/BinarySearch/BinarySearchwithBuiltInToolsUpperBound.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/69.Sqrtx: LeetcodeGrind/BinarySearch/69.Sqrtx.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/69.SqrtxRecursive: LeetcodeGrind/BinarySearch/69.SqrtxRecursive.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/374.GuessNumberHigherOrLower: LeetcodeGrind/BinarySearch/374.GuessNumberHigherOrLower.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


$(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch: LeetcodeGrind/BinarySearch/BinarySearchVariationsTheoryBoundaryVsExactMatch.cpp | $(EXEC_DIR)
	g++ -g $< -o $@



# Directory PART
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
					$(ASM_DIR)/374.GuessNumberHigherOrLower.S $(EXEC_DIR)/374.GuessNumberHigherOrLower $(ASM_DIR)/374.GuessNumberHigherOrLower.S \
					$(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S $(EXEC_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch $(ASM_DIR)/BinarySearchVariationsTheoryBoundaryVsExactMatch.S \

# Also, consider adding a .PHONY directive for the clean target to prevent potential issues if a file named clean exists in your directory
.PHONY: clean
clean:
	rm -rf $(FILES_TO_CLEAN) $(ASM_DIR) $(EXEC_DIR)
