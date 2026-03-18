

int PatternLight::GetShape(){
    return m_light;
}

bool PatternLight::SetShape(int shape){
    if(shape >= NO_SHAPE && shape <= MAX_SHAPE){
        m_shape = shape;
        return true;
    }
    else{
        return false;
    }
}

ostream& operator << (ostream& ostr, const PatternLight& patternLight){
    ostr << static_cast<Light> patternLight;
    if(patternLight.m_on && patternLight.m_shape != NO_SHAPE){
        ostr << ", showing";
        switch{

        }
    }
}
