#include "row.h"
#include <Arduino.h>

Row::Row(bool isCommonAnode, int redPin, int greenPin, int bluePin):
  m_redPin(redPin),
  m_greenPin(greenPin),
  m_bluePin(bluePin),
  m_isCommonAnode(isCommonAnode)
{
  // Setup the pins for output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Set all intensities to 100%
  setIntensity(1.0f);
}

void Row::setIntensity(float redIntensity, float greenIntensity, float blueIntensity)
{
  int _redIntensity = redIntensity * 255;
  int _greenIntensity = greenIntensity * 255;
  int _blueIntensity = blueIntensity * 255;

  if (m_isCommonAnode)
  {
    _redIntensity = 255 - _redIntensity;
    _greenIntensity = 255 - _greenIntensity;
    _blueIntensity = 255 - _blueIntensity;
  }

  analogWrite(m_redPin, _redIntensity);
  analogWrite(m_greenPin, _greenIntensity);
  analogWrite(m_bluePin, _blueIntensity);
}

void Row::setIntensity(float allIntensity)
{
    setIntensity(allIntensity, allIntensity, allIntensity);
}
