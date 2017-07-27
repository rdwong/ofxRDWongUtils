//
//  RDWongSpinners.h
//  httpTest
//
//  Created by richard on 27/07/2017.
//
//

#ifndef httpTest_RDWongSpinners_h
#define httpTest_RDWongSpinners_h

#include "ofMain.h"


static void rdwDoubleSpinner(float xp, float yp, float radius=5)
{
    float circleRadius = radius*0.25;
    float time = ofGetElapsedTimef()*6;
    float r = radius*1.5 + 0.5*radius*sin(ofGetElapsedTimef()*1.5);
    ofDrawCircle(xp + r*cos(time), yp + r*sin(time), circleRadius);
    ofDrawCircle(xp - r*cos(time), yp - r*sin(time), circleRadius);
};

static void rdwDragonBallz(float x, float y, int numBalls=5, float baseRadius=8)
{
    float ballRadius = baseRadius*0.2;
    float time = ofGetElapsedTimef()*3;
    float interval = TWO_PI/numBalls;
    for (float angle = -PI; angle < PI; angle += interval) {
        float xp = x + baseRadius*cos(time + angle);
        float yp = y + baseRadius*sin(time + angle);
        ofDrawCircle(xp, yp, ballRadius);
    }
};

static void rdwLineTwister(float x, float y, float xradius=10, float yradius=10)
{
    float time = PI*ofGetElapsedTimef();
    
    for (float yp = -yradius; yp <= yradius; yp ++) {
        float z = PI*yp/yradius;
        float wd = xradius*0.7 + xradius*0.3*sin(time + z);
        ofDrawLine(x - wd, yp + y, x + wd, yp+ y);
    }
};

static void rdwLineSpinner(float xp, float yp, float radius=10)
{
    float time = ofGetElapsedTimef()*6;
    float offx = radius*cos(time);
    float offy = radius*sin(time);
    ofDrawLine(xp+offx, yp+offy, xp-offx, yp-offy);
    offx = radius*0.5*cos(time*0.5);
    offy = radius*0.5*sin(time*0.5);
    ofDrawLine(xp+offx, yp-offy, xp-offx, yp+offy);
};

#endif
