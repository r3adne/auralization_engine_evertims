# EvertSE: Auralization Engine of the EVERTims project

#### zac-towbes fork of EVERTims/auralization-engine-evertims

Pre-compiled application may already exist for your architecture, check the install section of the [EVERTims website](https://evertims.github.io/website).  The installation described here targets developers involved in the project.

## zac-towbes/auralization-engine-evertims
is a forked version of EVERTims/auralization-engine-evertims. I am adding some extra functionality:

1. frequency-dependant gain in air absorption calculation
* warning user when gain is greater than 1.f or less than 0.f but not prohibiting it (This will lead to instability but it could be fun for cases when users want extreme (and intentionally inaccurate) effects)
* the ability to name saved IR files and specify their path
* creating a host VST plugin

This work is being done for the partial fulfillment of the EP-491 curriculum at Berklee College of Music. 

If you can see this message, the project is currently incomplete. 


## Install OSX

* install dependencies: run the ./libs/build_macos.sh script
* Install [JUCE's Projucer](http://www.juce.com/)
* Install [XCode](https://developer.apple.com/xcode/)
* Open ./EvertSE.jucer in Projucer, **from there** open the Xcode project
* Compile the project in XCode

## Externals libraries and dependencies

This software uses the JUCE C++ framework, available under both the GPL License and a commercial license. More information on http://www.juce.com.

other libraries being used:
* Eigen (MPL2, http://eigen.tuxfamily.org), 
* Ambix (GPL v2, https://github.com/kronihias/ambix/blob/master/README.md)