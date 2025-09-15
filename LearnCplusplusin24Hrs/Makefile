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


#The | symbol denotes an "order-only" dependency, meaning the directory needs to exist before the target is built,
# but changes to the directory itself won't trigger a build.

# -fverbose-asm adds inline comments to the assembly showing the original C++ lines and sometimes demangled names.
# You can also demangle the whole assembly with command ' c++filt < BoxMaker.s > demangled.s

#The $@ in the compile commands refer to the target file name

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

$(ASM_DIR)/BinarySearchTraditional.S: LeetcodeGrind/BinarySearchTraditional.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@

$(ASM_DIR)/BinarySearchFindUpperBound.S: LeetcodeGrind/BinarySearchFindUpperBound.cpp | $(ASM_DIR)
	g++ -S \
	-O0	\
	BoxMaker.cpp \
	-o $@


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

$(EXEC_DIR)/BinarySearchTraditional: LeetcodeGrind/BinarySearchTraditional.cpp | $(EXEC_DIR)
	g++ -g $< -o $@

$(EXEC_DIR)/BinarySearchFindUpperBound: LeetcodeGrind/BinarySearchFindUpperBound.cpp | $(EXEC_DIR)
	g++ -g $< -o $@


#----------------------------------------------------------------------------------------------------------------------------------------------
$(ASM_DIR) $(EXEC_DIR):
	mkdir -p $@

FILES_TO_CLEAN = $(ASM_DIR)/BoxMaker.S $(EXEC_DIR)/BoxMaker $(ASM_DIR)/BoxMakerdemangled.S \
					$(ASM_DIR)/TricycleClassOOP.S $(EXEC_DIR)/TricycleClassOOP $(ASM_DIR)/TricycleClassOOPdemangled.S \
					$(ASM_DIR)/NewTricycle.S $(EXEC_DIR)/NewTricycle $(ASM_DIR)/NewTricycledemangled.S \
					$(ASM_DIR)/Tricycle.S $(EXEC_DIR)/Tricycle $(ASM_DIR)/Tricycledemangled.S \
					$(ASM_DIR)/Rectangle.S $(EXEC_DIR)/Rectangle $(ASM_DIR)/Rectangledemangled.S \
					$(ASM_DIR)/RectangleOverloading.S $(EXEC_DIR)/RectangleOverloading $(ASM_DIR)/RectangleOverloadingdemangled.S \
					$(ASM_DIR)/BinarySearchTraditional.S $(EXEC_DIR)/BinarySearchTraditional $(ASM_DIR)/BinarySearchTraditionaldemangled.S \
					$(ASM_DIR)/BinarySearchFindUpperBound.S $(EXEC_DIR)/BinarySearchFindUpperBound $(ASM_DIR)/BinarySearchFindUpperBounddemangled.S \

# Also, consider adding a .PHONY directive for the clean target to prevent potential issues if a file named clean exists in your directory
.PHONY: clean
clean:
	rm -rf $(FILES_TO_CLEAN) $(ASM_DIR) $(EXEC_DIR)
