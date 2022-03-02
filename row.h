#pragma once

class Row
{
  public:
    Row(bool isCommonAnode, int redPin, int greenPin, int bluePin);
    
    void setIntensity(float redIntensity, float blueIntensity, float greenIntensity);
    void setIntensity(float allIntensity);
      
  private:
      int m_redPin;
      int m_greenPin;
      int m_bluePin;
      bool m_isCommonAnode;
};
