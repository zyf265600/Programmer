import { Component } from '@angular/core';
import { NgForm, Validators } from '@angular/forms';
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
    console.log(this.contactForm.value.fullName?.firstName);
    console.log(this.contactForm.value.fullName?.lastName);
    console.log(this.contactForm.get(["fullName", "firstName"])?.value);
    console.log(this.contactForm.valid)
    console.log(this.contactForm.ph)
  }

  contactForm = new FormGroup({
    fullName: new FormGroup({
      firstName: new FormControl(),
      lastName: new FormControl()
    }),
    phone: new FormControl(66666666666, [
      Validators.required,
      Validators.minLength(2),
      Validators.maxLength(11)]),
  });

  get phone(){
    return this.contactForm.get("phone");
  }

}
