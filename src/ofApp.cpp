//  CS 134 - In-Class exercise - Getting started with Particle Physics
//
//  Kevin M. Smith - CS 134 - SJSU CS

#include "ofApp.h"

//--------------------------------------------------------------
//  Setup Application data
//
void ofApp::setup(){
	cam.setDistance(10);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	ofSetFrameRate(60);


	// some simple sliders to play with parameters
	//
	gui.setup();
	gui.add(velocity.setup("Initial Velocity - Radial", ofVec3f(0, 20, 0), ofVec3f(0, 0, 0), ofVec3f(100, 100, 100)));	
	gui.add(lifespan.setup("Lifespan", 2.0, .1, 10.0));
	gui.add(rate.setup("Rate", 1.0, .5, 60.0));
	gui.add(damping.setup("Damping", .99, .1, 1.0));
    gui.add(gravity.setup("Gravity", 10, 1, 20));
	gui.add(radius.setup("Radius", .1, .01, .3));
	gui.add(mass.setup("Mass", 10, 1, 30));
	bHide = false;
    // sliders for emitter 2
    gui.add(velocity2.setup("Initial Velocity - Sphere", ofVec3f(0, 20, 0), ofVec3f(0, 0, 0), ofVec3f(100, 100, 100)));	
	gui.add(lifespan2.setup("Lifespan2", 2.0, .1, 10.0));
	gui.add(rate2.setup("Rate2", 1.0, .5, 60.0));
	gui.add(damping2.setup("Damping2", .99, .1, 1.0));
    gui.add(gravity2.setup("Gravity2", 10, 1, 20));
	gui.add(radius2.setup("Radius2", .1, .01, .3));
	gui.add(mass2.setup("Mass2", 10, 1, 30));
	// start up the emitter
	// 
	emitter.sys->addForce(new TurbulenceForce(ofVec3f(-2, -1, -3), ofVec3f(1, 2, 5)));
	emitter.sys->addForce(new GravityForce(ofVec3f(0, -gravity, 0)));
    emitter.sys->addForce(new ImpulseRadialForce(1000));
    emitter.setVelocity(ofVec3f(0, 0, 0));
    emitter.setOneShot(true);
    emitter.setEmitterType(RadialEmitter);
    emitter.setGroupSize(500);
    emitter.setColor(ofColor::aquamarine);
    // start up the second emitter
	emitter2.sys->addForce(new TurbulenceForce(ofVec3f(-2, -1, -3), ofVec3f(1, 2, 5)));
	emitter2.sys->addForce(new GravityForce(ofVec3f(0, -gravity, 0)));
    emitter2.sys->addForce(new ImpulseRadialForce(1000));
    //emitter2.setVelocity(ofVec3f(0, 0, 0));
    emitter2.setOneShot(true);
    emitter2.setEmitterType(RadialEmitter);
    emitter2.setGroupSize(500);
    emitter2.setColor(ofColor::red);
}

//--------------------------------------------------------------
//
void ofApp::update() {
	ofSeedRandom();

	emitter.setLifespan(lifespan);
	emitter.setRate(rate);
	emitter.setParticleRadius(radius);
	emitter.setMass(mass);
	emitter.update();

    emitter2.setVelocity(velocity2);
	emitter2.setLifespan(lifespan2);
	emitter2.setRate(rate2);
	emitter2.setParticleRadius(radius2);
	emitter2.setMass(mass2);
	emitter2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);

	// draw the GUI
	if (!bHide) gui.draw();

	// begin drawing in the camera
	//
	cam.begin();

	// draw a grid
	//
	ofPushMatrix();
	ofRotate(90, 0, 0, 1);
	ofSetLineWidth(1);
	ofSetColor(ofColor::dimGrey);
	ofDrawGridPlane();
	ofPopMatrix();

	// draw particle emitter here..
	//
	emitter.draw();
    emitter2.draw();

	//  end drawing in the camera
	// 
	cam.end();

	// draw screen data
	//
	string str;
	str += "Frame Rate: " + std::to_string(ofGetFrameRate());
	ofSetColor(ofColor::white);
	ofDrawBitmapString(str, ofGetWindowWidth() -170, 15);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'C':
	case 'c':
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
		break;
	case 'F':
	case 'b':
		break;
	case 'f':
		ofToggleFullscreen();
		break;
	case 'h':
		bHide = !bHide;
	case ' ':
		emitter.sys->reset();
		emitter.start();
        emitter2.sys->reset();
		emitter2.start();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
