#include<bits/stdc++.h>
using namespace std;

//this class was created in order to be inherited by other classes.
class templateClass{
private:
    string name;
    string ID;
    string inputPath;
    string outputPath;
protected:
    //reference to *ID*
    string &refID(){ return ID;  }
    //reference to *name*
    string &refName(){ return name; }
    //reference to *inputPath*
    string &refInputPath(){ return inputPath; }
    //reference to *outputPath*
    string &refOutputPath(){ return outputPath; }
public:
    //constructor template_class
    templateClass(string defaultName = "unknown", 
                            string defaultID = "unknown",
                            string defaultInputPath = "unknown",
                            string defaultOutputPath = "unknown"){
        name   = defaultName,
        ID         = defaultID,
        inputPath = defaultInputPath,
        outputPath = defaultOutputPath;
    }
    virtual  void setName(string newName){
        this->name = newName;
    }
    virtual string getName(){
        return this->name;
    }
    virtual  void setID(string newID){
        this->ID = newID;
    }
    virtual string getID(){
        return this->ID;
    }
    virtual void setInputFilePath(string newPath){
        inputPath = newPath;
    }
    virtual void setOutputFilePath(string newPath){
        outputPath = newPath;
    }
    virtual string getInputPath(){
        return inputPath;
    }
    virtual string  getOutputPath(){
        return outputPath;
    };
};