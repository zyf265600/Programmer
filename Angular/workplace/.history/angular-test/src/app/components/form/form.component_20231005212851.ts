import { Component } from '@angular/core';
import { NgForm } from '@angular/forms';
import {}

@Component({
  selector: 'app-form',
  templateUrl: './form.component.html',
  styleUrls: ['./form.component.css']
})
export class FormComponent {
  onSubmit(form: NgForm) {
    console.log(form.valid);
  }

  
  
}
