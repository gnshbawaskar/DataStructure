package com.example.userservice;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

@Service
public class UserService {

    @Autowired
    private UserRepository userRepository;

    public boolean registerUser(UsersAuth user) {
        List<UsersAuth> allUser = new ArrayList<UsersAuth>();
        allUser = userRepository.findAll();
        for (UsersAuth usr : allUser) {
            if (null == usr)
                return false;
            if (usr.username.equals(user.username))
                return false;
        }

        userRepository.save(user);
        return true;
    }

    public boolean loginUser(LoginRequest loginRequest) {
        List<UsersAuth> allUser = new ArrayList<UsersAuth>();
        allUser = userRepository.findAll();
        for (UsersAuth usr : allUser) {
            boolean result = false;
            if ((usr.username.equals(loginRequest.getUsername()))) {
                if ((usr.password.equals(loginRequest.getPassword()))) {
                    return true;
                }
            }
        }
        return false;
    }

    public AuthResponse authorize(String AuthToken){
        List<UsersAuth> allUser = new ArrayList<UsersAuth>();
        allUser = userRepository.findAll();
        AuthResponse res = new AuthResponse();
        res.status = "FAIL";
        res.username = "";
        for (UsersAuth usr : allUser) {
            boolean result = false;
            if ((usr.authToken.equals(AuthToken))) {
                    res = new AuthResponse();
                    res.username = usr.username;
                    res.status = "SUCCESS";
                    return res;
            }
        }
        return res;
    }
}