
#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1000);
    Energy = 1.25 * MeV;
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen() {

}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleEnergy(Energy);

    gun->SetParticlePosition(G4ThreeVector(0,0,0));

    double x = 2*G4UniformRand()-1;
    double y = 2*G4UniformRand()-1;
    double z = 2*G4UniformRand()-1;
    double r = sqrt(x*x + y*y + z*z);

    gun->SetParticleMomentumDirection(G4ThreeVector(x/r, y/r, z/r));

    gun->GeneratePrimaryVertex(anEvent);
}