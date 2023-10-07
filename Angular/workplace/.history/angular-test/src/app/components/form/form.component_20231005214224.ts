import { Component } from '@angular/core';
import { NgForm } from '@angular/forms';
import { FormControl, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-form',
  templateUrl: './form.component.html',
  styleUrls: ['./form.component.css']
})
export class FormComponent {
  on_Submit(form: NgForm) {
    console.log(form.valid);
  }

  onSubmit() {
    console.log(this.contactForm.value);
  }

  contactForm = new FormGroup({
    name: new FormControl("default name"),
    phone: new FormControl(66666666666),
  });
  
}
