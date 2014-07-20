#include "ofApp.h"
int numPattern = 30;
int numStroke = 3;
int col = 6;
int row = 6;
int strokeLength = 100;
int pattenrSapce = 200;
float decay = 5.0;
void drawTri(int tx , int ty)
{
    for( int i = 0 ; i < numStroke ; i++)
    {
        float x = sin(i*(TWO_PI/numStroke))*strokeLength+tx;
        float y = cos(i*(TWO_PI/numStroke))*strokeLength+ty;
        ofLine(tx , ty ,x,y);
    }
    
}
//--------------------------------------------------------------
void ofApp::setup(){
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    ofEnableSmoothing();
    ofSetLineWidth(10);
    gui = new ofxUISuperCanvas("SETTING", 0, 0, 300, 768);
    
	gui->addIntSlider("NUMPATTERN", 0, 200,&numPattern);
    gui->addIntSlider("NUMSTROKE", 0, 50,&numStroke);
    gui->addIntSlider("COL", 0, 20,&col);
    gui->addIntSlider("ROW", 0, 20,&row);
    gui->addIntSlider("STROKE_LEN", 0, 200,&strokeLength);
    gui->addIntSlider("PATTERN_SPACE", 0, 400,&pattenrSapce);
    gui->addSlider("decay", 0, 200,&decay);
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
    for(int i = 0 ; i < numPattern ; i++)
    {
        float tx = (i%col)*(pattenrSapce);
        float ty = (i/row)*pattenrSapce;
        for( int i = 0 ; i < numStroke ; i++)
        {
            float x = sin(i*(TWO_PI/numStroke))*strokeLength;
            float y = cos(i*(TWO_PI/numStroke))*strokeLength;
            ofVec3f v1 = ofVec3f(tx , ty,0);
            ofVec3f v2 = ofVec3f(tx+x , ty+y,0);
            mesh.addVertex(v1);
            mesh.addVertex(v2);
        }
    }
    vbo = mesh;
}
void ofApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.getName();
	int kind = e.getKind();
	cout << "got event from: " << name << endl;
    if(name=="NUMPATTERN")
    {
        mesh.clear();
        for(int i = 0 ; i < numPattern ; i++)
        {
            for( int j = 0 ; j < numStroke ; j++)
            {
                
                mesh.addVertex(ofVec3f(0,0));
                mesh.addVertex(ofVec3f(0,0));
            }
        }

        vbo = mesh;
    }
    if(name=="NUMSTROKE")
    {
        mesh.clear();
        for(int i = 0 ; i < numPattern ; i++)
        {
            for( int j = 0 ; j < numStroke ; j++)
            {
                
                mesh.addVertex(ofVec3f(0,0));
                mesh.addVertex(ofVec3f(0,0));
            }
        }
        vbo = mesh;

    }


}
//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    int index = 0;
    for(int i = 0 ; i < numPattern ; i++)
    {
        float tx = (i%col)*(pattenrSapce);
        float ty = (i/row)*pattenrSapce;
        float r = ofGetFrameNum()/decay*(((i/row)%2==0)?-1:1);
        for( int j = 0 ; j < numStroke ; j++)
        {

            float x = sin(j*(TWO_PI/numStroke)+r)*strokeLength;
            float y = cos(j*(TWO_PI/numStroke)+r)*strokeLength;
            ofVec3f v1 = ofVec3f(tx , ty,0);
            ofVec3f v2 = ofVec3f(tx+x , ty+y,0);
            mesh.setVertex(index,v1);
            index++;
            mesh.setVertex(index,v2);
            index++;
        }
    }
    vbo = mesh;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    
    
    vbo.drawWireframe();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key)
    {
            case 'h':
            gui->toggleVisible();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
