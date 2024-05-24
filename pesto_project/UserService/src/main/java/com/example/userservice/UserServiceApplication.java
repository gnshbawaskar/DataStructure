package com.example.userservice;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.Base64;

@RestController
@RequestMapping("/users")
@SpringBootApplication
public class UserServiceApplication {

    public static void main(String[] args) {
        SpringApplication.run(UserServiceApplication.class, args);
    }
    @Autowired
    private UserService userService;

    @PostMapping("/register")
    public ResponseEntity<RegisterResponse> registerUser(@RequestBody UsersAuth user) {
        String authToken = Base64.getEncoder().encodeToString(user.password.getBytes());
        authToken += Base64.getEncoder().encodeToString(user.username.getBytes());
        user.authToken = authToken;
        boolean ret = userService.registerUser(user);
        RegisterResponse response = new RegisterResponse();
        if (ret){
            response.setStatus("registered successfully");
            response.setAuthToken(authToken);
        }else{
            response.setStatus("User already exists!");
            response.setAuthToken("null");
        }
        return ResponseEntity.ok(response);
    }

    @PostMapping("/login")
    public ResponseEntity<String> loginUser(@RequestBody LoginRequest loginRequest) {
        boolean ret = userService.loginUser(loginRequest);
        String result;
        if (ret)
        {
            result = "Login successful";
        }else{
            result = "Login failed";
        }
        return ResponseEntity.ok(result);
    }

    @GetMapping("/authorize")
    public ResponseEntity<AuthResponse> authorize(@RequestHeader("Auth-Token") String AuthToken) {
        return ResponseEntity.ok(userService.authorize(AuthToken));
    }
}
