#pragma once
#include "stdincl.h"
#include "Profile.h"

class ProfilesManager
{
public:
	ProfilesManager();
	~ProfilesManager();

	void						CreateProfile(const std::string& name);
	bool						ProfileAvailable(const std::string& name);
	void						UnloadCurrentProfile();
	Profile*					GetCurrentProfile();
	void						SetCurrentProfile(const Profile& p);

	void						GetProfiles(std::vector<Profile>& profiles);


private:

	Profile						m_currentProfile;

};

extern ProfilesManager* g_profilesManager;