import { Component } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';
import { Router } from "@angular/router"
import { CanLeave } from 'src/app/guards/unsave.guard';

@Component({
  selector: 'app-router',
  templateUrl: './router.component.html',
  styleUrls: ['./router.component.css']
})
export class RouterComponent{
  
  constructor(private router: Router) { }

  jump() {
    this.router.navigate(['/navigator'], {
      queryParams: {
        name: "Kitty"
      }
    });
  }
}
