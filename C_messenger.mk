##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=C_messenger
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1
ProjectPath            :=C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/C_messenger
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/C_messenger
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=marti
Date                   :=12/10/2025
CodeLitePath           :=C:/Programming/CodeLite
MakeDirCommand         :=mkdir -p
LinkerName             :=C:/cygwin64/bin/gcc.exe
SharedObjectLinkerName :=C:/cygwin64/bin/gcc.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/cygwin64/bin/ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
CC       := C:/cygwin64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -O0 -gdwarf-2 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Programming\CodeLite
Objects0=$(IntermediateDirectory)/client.c$(ObjectSuffix) $(IntermediateDirectory)/menu.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/message.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/client.c$(ObjectSuffix): client.c $(IntermediateDirectory)/client.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/C_messenger/client.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/client.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/client.c$(DependSuffix): client.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/client.c$(ObjectSuffix) -MF$(IntermediateDirectory)/client.c$(DependSuffix) -MM client.c

$(IntermediateDirectory)/client.c$(PreprocessSuffix): client.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/client.c$(PreprocessSuffix) client.c

$(IntermediateDirectory)/menu.c$(ObjectSuffix): menu.c $(IntermediateDirectory)/menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/C_messenger/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menu.c$(DependSuffix): menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/menu.c$(DependSuffix) -MM menu.c

$(IntermediateDirectory)/menu.c$(PreprocessSuffix): menu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menu.c$(PreprocessSuffix) menu.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/C_messenger/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/message.c$(ObjectSuffix): message.c $(IntermediateDirectory)/message.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/dolezite/ProgrammingAndProjects/CWorkspaces/Workspace1/C_messenger/message.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/message.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/message.c$(DependSuffix): message.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/message.c$(ObjectSuffix) -MF$(IntermediateDirectory)/message.c$(DependSuffix) -MM message.c

$(IntermediateDirectory)/message.c$(PreprocessSuffix): message.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/message.c$(PreprocessSuffix) message.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


