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


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    for(int i = 0 ; i < numPattern ; i++)
    {
        ofPushMatrix();
        ofTranslate((i%col)*(pattenrSapce), (i/row)*pattenrSapce);
        ofRotate(ofGetFrameNum()/decay*(((i/row)%2==0)?-1:1), 0, 0, 1);

        drawTri(0 ,0);
        ofPopMatrix();
    }

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
